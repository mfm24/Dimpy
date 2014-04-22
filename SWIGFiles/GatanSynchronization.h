
#ifndef __GATANSYNCHRONIZATION__
#define __GATANSYNCHRONIZATION__

#include "GatanTypes.h"
#include "GatanInterface.h"
#include "GatanFoundationBase.h"

#ifdef _GATAN_OS_WIN32

namespace Gatan { namespace Win32
{
	class TickTiming_OS
	{
	public:
		typedef uint32 tick_type;
		typedef sint32 diff_type;
	public:
		gtn_force_inline void get_current_tick( volatile tick_type &tick_count ) const _GATAN_THROW_0
			{ tick_count = ::GetTickCount(); }
		gtn_force_inline void get_ticks_per_second( tick_type &tick_res ) const _GATAN_THROW_0
			{ tick_res = 1000; }
		gtn_force_inline diff_type calc_tick_diff( tick_type tick_0, tick_type tick_1 ) const _GATAN_THROW_0
			{ return (diff_type) ( tick_1 - tick_0 ); }
	};
	class TickTiming_Performance
	{
	public:
		typedef uint64 tick_type;
		typedef sint64 diff_type;
	private:
		typedef BOOL (WINAPI *TickTimingProc)( PLARGE_INTEGER val );

		TickTimingProc   fTickCountProc;
		TickTimingProc   fCalcTicksPerSecondProc;
	public:
		TickTiming_Performance();
		gtn_force_inline void get_current_tick( volatile tick_type &tick_count ) const _GATAN_THROW_0
			{ (*fTickCountProc)( (PLARGE_INTEGER) &tick_count ); }
		gtn_force_inline void get_ticks_per_second( tick_type &tick_res ) const _GATAN_THROW_0
			{ (*fCalcTicksPerSecondProc)( (PLARGE_INTEGER) &tick_res ); }
		gtn_force_inline diff_type calc_tick_diff( tick_type tick_0, tick_type tick_1 ) const _GATAN_THROW_0
			{ return (diff_type) ( tick_1 - tick_0 ); }
	};
	class TickTiming_IA32_RDTSC
	{
	public:
		typedef uint64 tick_type;
		typedef sint64 diff_type;
		
		class calibration
		{
		public:
			struct sample_t
			{
				uint64 calib_tick;
				uint64 rdtsc_tick;
			};
		private:
			TickTiming_Performance calib_tick_time;
			DWORD  thread_affinity_mask;		// Specifies processor on which the performance is being calibrated
			
			DWORD calc_thread_affinity_mask();
		public:
			calibration()
				: thread_affinity_mask(0)
			{}

			void  get_samples( ulong num_samples, sample_t *samples ) const;

			void start_calibration();
			void end_calibration();
			uint64 calc_rdtsc_ticks_per_second( ulong num_samples
			                                  , const sample_t *samples_0
			                                  , const sample_t *samples_1 ) const;
		};
	private:
		uint64 (*fTickCountProc)();
		uint64 fTicksPerSecond;
	public:
		TickTiming_IA32_RDTSC();
		gtn_force_inline void get_current_tick( volatile tick_type &tick_count ) const _GATAN_THROW_0
			{ tick_count = (*fTickCountProc)(); }
		gtn_force_inline void get_ticks_per_second( tick_type &tick_res ) const _GATAN_THROW_0
			{ tick_res = fTicksPerSecond; }
		gtn_force_inline diff_type calc_tick_diff( tick_type tick_0, tick_type tick_1 ) const _GATAN_THROW_0
			{ return (diff_type) ( tick_1 - tick_0 ); }
	};

	typedef TickTiming_Performance TickTiming_HighRes;
	typedef TickTiming_IA32_RDTSC  TickTiming_Processor;

	class Timing
	{
	public:
		Timing();
		~Timing();

		uint32 GetTicksPerDoubleClick() const _GATAN_THROW_0;
	};
} } // namespace Win32 // namespace Gatan

#endif // _GATAN_OS_WIN32
#ifdef _GATAN_OS_MACOS

#include <CoreServices/CoreServices.h>


namespace Gatan { namespace Macintosh
{
	class TickTiming_OS
	{
	public:
		typedef uint32 tick_type;
		typedef sint32 diff_type;
	public:
		gtn_force_inline void get_current_tick( volatile tick_type &tick_count ) const _GATAN_THROW_0
			{ tick_count = ::TickCount(); }
		gtn_force_inline void get_ticks_per_second( tick_type &tick_res ) const _GATAN_THROW_0
			{ tick_res = 60; }
		gtn_force_inline diff_type calc_tick_diff( tick_type tick_0, tick_type tick_1 ) const _GATAN_THROW_0
			{ return (diff_type) ( tick_1 - tick_0 ); }
	};
	class TickTiming_Microsecond
	{
	public:
		typedef uint64 tick_type;
		typedef sint64 diff_type;
	public:
		gtn_force_inline void get_current_tick( volatile tick_type &tick_count ) const _GATAN_THROW_0
			{ Microseconds( (UnsignedWide *) &tick_count ); }
		gtn_force_inline void get_ticks_per_second( tick_type &tick_res ) const _GATAN_THROW_0
			{ tick_res = 1000000; }
		gtn_force_inline diff_type calc_tick_diff( tick_type tick_0, tick_type tick_1 ) const _GATAN_THROW_0
			{ return (diff_type) ( tick_1 - tick_0 ); }
	};

	typedef TickTiming_Microsecond TickTiming_HighRes;
	typedef TickTiming_Microsecond TickTiming_Processor;

	class Timing
	{
	public:
		Timing();
		~Timing();

		uint32 GetTicksPerDoubleClick() const _GATAN_THROW_0;
	};
} } // namespace Macintosh // namespace Gatan

#endif // _GATAN_OS_MACOS


namespace Gatan
{
	template <typename TickTimingType> typename TickTimingType::tick_type
		CalculateTickTimingResolution( const TickTimingType &tick_timing, ulong num_iter )
	{
		typedef typename TickTimingType::tick_type tick_type;

		tick_type tick_res = std::numeric_limits<tick_type>::max();
		for( ulong i_iter = 0; i_iter < num_iter; ++i_iter )
		{
			tick_type tick_prev = 0, tick_cur = 0;
			tick_timing.get_current_tick( tick_prev );
			tick_timing.get_current_tick( tick_cur );
			while( tick_cur == tick_prev )
			{
				tick_timing.get_current_tick( tick_cur );
			}
			tick_res  = std::min( tick_res, (tick_cur-tick_prev) );
		}
		return tick_res;
	}

	class GFTiming : public OS::Timing
	{
	public:
		typedef uint32 low_res_tick_type;
		typedef uint64 high_res_tick_type;
		typedef uint64 proc_res_tick_type;
	private:
		OS::TickTiming_OS         fTickTiming_OS;
		low_res_tick_type         fTickResolution_OS;		// Resolution is minimum change between two different tick counts
		low_res_tick_type         fTicksPerSecond_OS;

		OS::TickTiming_HighRes    fTickTiming_HighRes;
		high_res_tick_type        fTickResolution_HighRes;
		high_res_tick_type        fTicksPerSecond_HighRes;
		
		OS::TickTiming_Processor  fTickTiming_Processor;
		proc_res_tick_type        fTickResolution_Processor;
		proc_res_tick_type        fTicksPerSecond_Processor;
	public:
		GFTiming();
		~GFTiming();

		const OS::TickTiming_OS        &GetOSTickTiming() const        { return fTickTiming_OS; }
		const OS::TickTiming_HighRes   &GetHighResTickTiming() const   { return fTickTiming_HighRes; }
		const OS::TickTiming_Processor &GetProcessorTickTiming() const { return fTickTiming_Processor; }

		gtn_force_inline void GetOSTickCount( volatile low_res_tick_type &tick_count ) const _GATAN_THROW_0
			{ fTickTiming_OS.get_current_tick( tick_count ); }

		gtn_force_inline void GetOSTicksPerSecond( low_res_tick_type &tick_res ) const _GATAN_THROW_0
			{ tick_res = fTicksPerSecond_OS; }

		gtn_force_inline low_res_tick_type GetOSTickResolution() const _GATAN_THROW_0
			{ return fTickResolution_OS; }

		gtn_force_inline double CalcOSSecondsBetween( low_res_tick_type start_tick, low_res_tick_type end_tick ) const _GATAN_THROW_0
			{ return (double) fTickTiming_OS.calc_tick_diff( start_tick, end_tick ) / (double) (sint32) fTicksPerSecond_OS; }



		gtn_force_inline void GetHighResTickCount( volatile high_res_tick_type &tick_count ) const _GATAN_THROW_0
			{ fTickTiming_HighRes.get_current_tick( tick_count ); }

		gtn_force_inline void GetHighResTicksPerSecond( high_res_tick_type &tick_res ) const _GATAN_THROW_0
			{ tick_res = fTicksPerSecond_HighRes; }

		gtn_force_inline high_res_tick_type GetHighResTickResolution() const  _GATAN_THROW_0
			{ return fTickResolution_HighRes; }

		gtn_force_inline double CalcHighResSecondsBetween( high_res_tick_type start_tick, high_res_tick_type end_tick ) const _GATAN_THROW_0
			{ return (double) fTickTiming_HighRes.calc_tick_diff( start_tick, end_tick ) / (double) (sint64) fTicksPerSecond_HighRes; }



		gtn_force_inline void GetProcessorTickCount( volatile proc_res_tick_type &tick_count ) const _GATAN_THROW_0
			{ fTickTiming_Processor.get_current_tick( tick_count ); }

		gtn_force_inline void GetProcessorTicksPerSecond( proc_res_tick_type &tick_res ) const _GATAN_THROW_0
			{ tick_res = fTicksPerSecond_Processor; }

		gtn_force_inline proc_res_tick_type GetProcessorTickResolution() const  _GATAN_THROW_0
			{ return fTickResolution_Processor; }

		gtn_force_inline double CalcProcessorSecondsBetween( proc_res_tick_type start_tick, proc_res_tick_type end_tick ) const _GATAN_THROW_0
			{ return (double) fTickTiming_Processor.calc_tick_diff( start_tick, end_tick ) / (double) (sint64) fTicksPerSecond_HighRes; }
			
		class Init { public: Init(); ~Init(); };
	};
	static GFTiming::Init gSystemTimingInit;

	extern GFTiming *gSystemTiming;

	gtn_force_inline const GFTiming &GFGetSystemTiming() { return *gSystemTiming; }

	inline GFTiming::low_res_tick_type  GFGetOSTickCount() _GATAN_THROW_0
		{ GFTiming::low_res_tick_type tick_count; gSystemTiming->GetOSTickCount( tick_count ); return tick_count; }
	inline GFTiming::low_res_tick_type  GFGetOSTicksPerSecond() _GATAN_THROW_0
		{ GFTiming::low_res_tick_type tick_res; gSystemTiming->GetOSTicksPerSecond( tick_res ); return tick_res; }
	inline double GFCalcOSSecondsBetween( GFTiming::low_res_tick_type start_tick, GFTiming::low_res_tick_type end_tick ) _GATAN_THROW_0
		{ return gSystemTiming->CalcOSSecondsBetween( start_tick, end_tick ); }
	double GFCalcOSSecondsSince( GFTiming::low_res_tick_type ticks ) _GATAN_THROW_0;

	inline GFTiming::high_res_tick_type GFGetHighResTickCount() _GATAN_THROW_0
		{ GFTiming::high_res_tick_type tick_count; gSystemTiming->GetHighResTickCount( tick_count ); return tick_count; }
	inline GFTiming::high_res_tick_type GFGetHighResTicksPerSecond() _GATAN_THROW_0
		{ GFTiming::high_res_tick_type tick_res; gSystemTiming->GetHighResTicksPerSecond( tick_res ); return tick_res; }
	inline double GFCalcHighResSecondsBetween( GFTiming::high_res_tick_type start_tick, GFTiming::high_res_tick_type end_tick ) _GATAN_THROW_0
		{ return gSystemTiming->CalcHighResSecondsBetween( start_tick, end_tick ); }
	double GFCalcHighResSecondsSince( GFTiming::high_res_tick_type ticks ) _GATAN_THROW_0;


	inline GFTiming::proc_res_tick_type GFGetProcessorTickCount() _GATAN_THROW_0
		{ GFTiming::proc_res_tick_type tick_count; gSystemTiming->GetProcessorTickCount( tick_count ); return tick_count; }
	inline GFTiming::proc_res_tick_type GFGetProcessorTicksPerSecond() _GATAN_THROW_0
		{ GFTiming::proc_res_tick_type tick_res; gSystemTiming->GetProcessorTicksPerSecond( tick_res ); return tick_res; }
	inline double GFCalcProcessorSecondsBetween( GFTiming::proc_res_tick_type start_tick, GFTiming::proc_res_tick_type end_tick ) _GATAN_THROW_0
		{ return gSystemTiming->CalcProcessorSecondsBetween( start_tick, end_tick ); }
}

/*
** Synchronization
*/
namespace Gatan
{
	class GTN_I_Signal;
	class GTN_I_PeriodicTask;

	/*
	** Synchronization Overview
	**
	**    The following classes are utility classes intended to implement the common synchronization patterns
	** used in DM.  It is not extremely general, for instance not implementing a general wait for multiple objects
	** ( a wait may be specified to abort upon one of a set of signals being set, but these signals are interpreted
	** as cancels, so no indication is given as to which signal caused the abort ).
	**
	**    - In general, any wait for synchronization using the following classes can have one of 3 outcomes
	**         1) Synchronization succeeds
	**         2) Synchronization times out
	**         3) Synchronization is aborted
	**      A wait for synchronization method has the form 'bool <Wait>(...)', and a successful synchronization
	**      returns 'true', a timeout returns 'false', and an abort throws an exception.
	**
	**    Most of the synchronization objects are implemented as an abstract class derived from 'GFInterlockedRefCount'
	** whose concrete instances are created via a factory of type 'Synchronization'.  Making the classes abstract
	** allows hiding the implementation while deriving them from 'GFInterlockedRefCount' allows them to be shared without
	** worrying about ownership ( lifetime is handled via reference couting ).  The abstract synchronization types are
	**
	**    GTN_I_Signal       - A synchronization object implements this interface if it can be in one of two states,
	**                         signalled or unsignalled, and it allows waiting until it becomes signalled.
	**                            Win32: This is used to wrap 'EVENT' objects.
	**    GTN_I_Blockable    - A synchronization object implements this interface if it protects a resource, so one
	**                         must wait on the object for access to the resource and release access when done.  Both
	**                         mutexes and semaphores implement this interface.
	**    GTN_I_MessageQueue - Objects derived from 'GFRefCountableInterface' may be added to the queue, and multiple
	**                         clients may wait on the queue until an object is available.  The 'queue' part of the name
	**                         is not exactly appropriate, for an instantiation may issue the objects to clients in any
	**                         order it desires, and may issue the same object to multiple clients.
	**                         ( The only current instantiation, however, issues its objects as a queue would ).
	**
	**
	** Concrete classes
	**
	**    For speed, a few synchronization objects are not implmeneted as interfaces.  These include
	**
	**    CriticalSection - Like a mutex but without timeout or abort capabilities.  This is used for low-overhead
	**                      and fine-grained blocking blocking. ( Rarely should other locks be acquired while a lock
	**                      on a 'CriticalSection' is held, and the lock should not be held for long periods of time. )
	**    InterlockedRefCount - Implements a quantity that may be atomically incremented and decremented from multiple threads.
	**    InterlockedAmount   - Implements a quantity to which a sum can be atomically added from multiple threads.
	*/

	/*
	** struct SyncWaitAbortDesc
	**
	**    This structure is used to adjust the behavior of a wait on a synchronization object.
	**
	**       timeout             - specifies the time after which a wait will time out, or
	**                             'std::numeric_limits<double>::infinity()' if the wait will never time out.
	**       num_periodic_tasks
	**       periodic_tasks      - specifies a list of tasks that will be executed periodically during the
	**                             wait.
	**       num_signals
	**       signals             - specifies a list of signals that if any is raised will abort a wait.
	**
	**
	*/
	struct SyncWaitAbortDesc
	{
		double timeout;
		ulong  num_periodic_tasks;
		ref_ptr<GTN_I_PeriodicTask> *periodic_tasks;
		ulong  num_signals;
		ref_ptr<GTN_I_Signal> *signals;
		bool                             high_resolution;
			// 'true' if we should sacrifice cpu usage for faster response time for a wait

		SyncWaitAbortDesc( double timeout_in = std::numeric_limits<double>::infinity(), bool high_resolution_ = true )
			: timeout( timeout_in )
			, num_periodic_tasks( 0 )
			, periodic_tasks( NULL )
			, num_signals( 0 )
			, signals( NULL )
			, high_resolution( high_resolution_ )
		{}
		SyncWaitAbortDesc( double *timeout_in
		                 , ulong num_periodic_tasks_in, ref_ptr<GTN_I_PeriodicTask> *periodic_tasks_in
						 , ulong num_signals_in, ref_ptr<GTN_I_Signal> *signals_in )
			: timeout( ( timeout_in == NULL ) ? std::numeric_limits<double>::infinity() : *timeout_in )
			, num_periodic_tasks( num_periodic_tasks_in )
			, periodic_tasks( periodic_tasks_in )
			, num_signals( num_signals_in )
			, signals( signals_in )
			, high_resolution( true )
		{
		}

	};

	class GTN_I_Signal : public GFRefCountableInterface
	{
	public:
		virtual void SetSignal()                            = 0;
		virtual void ResetSignal()                          = 0;
		virtual bool WaitOnSignal_Self( const SyncWaitAbortDesc *abort_desc ) = 0;
	
		bool IsSignalled()
			{ SyncWaitAbortDesc abort_desc( 0.0 ); return WaitOnSignal_Self( &abort_desc ); }
		void WaitOnSignal()
			{ WaitOnSignal_Self( NULL ); }
		bool WaitOnSignal( double timeout_in )
			{ SyncWaitAbortDesc abort_desc( timeout_in ); return WaitOnSignal_Self( &abort_desc ); }
		bool WaitOnSignal( const SyncWaitAbortDesc *abort_desc )
			{ return WaitOnSignal_Self( abort_desc ); }
	};

	class GTN_I_PeriodicTask : public GFRefCountableInterface
	{
	public:
		virtual double GetMaxWait()            = 0;			// Maximum time before which 'DoAction' should be called again
		virtual void   DoAction()              = 0;			// Periodic action
		virtual uint32 GetTaskSignals( uint32 max_signals, ref_ptr<GTN_I_Signal> *signals ) = 0;
			// Returns a signal that is set when 'DoAction' should be run.  Can be 'NULL', indicating that it is sufficient
			// to wait til next call
	};

	class GTN_I_Blockable : public GFRefCountableInterface
	{
	public:
		virtual bool Acquire_Self( const SyncWaitAbortDesc *abort_desc )  = 0;
		virtual void Release_Self()  = 0;
	
		void Acquire()
			{ Acquire_Self( NULL ); }
		bool Acquire( const SyncWaitAbortDesc *abort_desc )
			{ return Acquire_Self( abort_desc ); }
		bool Acquire( double timeout_in )
			{ SyncWaitAbortDesc abort_desc( timeout_in ); return Acquire_Self( &abort_desc ); }
		void Release() { Release_Self(); }
	};

	class GTN_I_MessageQueue : public GFRefCountableInterface
	{
	public:
		typedef ref_ptr<GFRefCountableInterface> message_type;
	public:
		virtual message_type GetMessage_Self( const SyncWaitAbortDesc *abort_desc ) = 0;
		virtual void         PostMessage_Self( const message_type &message ) = 0;

		message_type GetMessage()
			{ return GetMessage_Self( NULL ); }
		message_type GetMessage( double timeout )
			{ SyncWaitAbortDesc abort_desc( timeout ); return GetMessage_Self( &abort_desc ); }
		message_type GetMessage( const SyncWaitAbortDesc *abort_desc )
			{ return GetMessage_Self( abort_desc ); }
		void PostMessage( const message_type &message )
			{ PostMessage_Self( message ); }
	};

	ref_ptr<GTN_I_MessageQueue> CreateMessageQueue_Std();

} // namespace Gatan

#ifdef _GATAN_OS_WIN32

namespace Gatan { namespace Win32
{
	class InterlockedRefCount
	{
	public:
		typedef Gatan::ulong count_type;
	private:
		LONG ref_count;
	public:
		gtn_force_inline InterlockedRefCount() : ref_count(0) {}
		gtn_force_inline InterlockedRefCount( const InterlockedRefCount & ) : ref_count(0) {}
		gtn_force_inline InterlockedRefCount &operator =( const InterlockedRefCount & ) { return *this; }
		gtn_force_inline        void  addRef() const { ::InterlockedIncrement( const_cast<LONG *>( &ref_count ) ); }
		gtn_force_inline Gatan::ulong remRef() const { return ::InterlockedDecrement( const_cast<LONG *>( &ref_count ) ); }
		gtn_force_inline Gatan::ulong numRef() const { return ref_count; }
	};

	class InterlockedAmount
	{
	public:
		typedef LONG AmountType;
	private:
		AmountType amount;				// !!!!! Should ensure that this is 32-bit aligned
	public:
		InterlockedAmount() : amount( 0 ) {}
		inline AmountType inc()    { return ( ::InterlockedIncrement( &amount ) - 1 ); }
		inline AmountType dec()    { return ::InterlockedDecrement( &amount ); }
		inline ulong val() const { return (ulong) amount; }
		inline AmountType exchange_add( long inc ) { return ::InterlockedExchangeAdd( &amount, inc ); }
		inline AmountType exchange( long new_val ) { return ::InterlockedExchange( &amount, new_val ); }

		static inline AmountType inc_val( AmountType &val ) { return ( ::InterlockedIncrement( &val ) - 1 ); }
		static inline AmountType dec_val( AmountType &val ) { return ::InterlockedDecrement( &val ); }

		static inline AmountType exchange_add_val( AmountType &val, long inc ) { return ::InterlockedExchangeAdd( &val, inc ); }
		static inline AmountType exchange_val( AmountType &val, long new_val ) { return ::InterlockedExchange( &val, new_val ); }
	};

	class Interlock
	{
	public:
		Interlock() : interlock( 0 ) {}
	
		bool acquire()    { return ::InterlockedExchange( &interlock, 1 ) == 0; }
			// try to acquire the interlock

		void clear()      { ::InterlockedExchange( &interlock, 0 ); }
			// clear the interlock.
	private:
		long interlock;
	};

	class Synchronization
	{
	public:
		Synchronization();
		~Synchronization();
		
		ref_ptr<GTN_I_Blockable> CreateMutex( bool initial_owner, const uncchar *name );
		ref_ptr<GTN_I_Blockable> CreateSemaphore( ulong initial_count, ulong max_count );
		ref_ptr<GTN_I_Signal>    CreateCancelSignal();

		/*
		** Create a 'GTN_I_Signal' object, initially set to the 'initially_signalled' state, which
		** retains its state until explicitly changed by its '{Set|Reset}Signal' methods.
		**    Win32: Implemented directly on handle returned by 'CreateEvent'
		*/
		ref_ptr<GTN_I_Signal>    CreateSignal( bool initially_signalled );
		
		/*
		** Create a 'GTN_I_MessageQueue' which issues queued objects to waiting clients in a
		** first-in-first-out manner, with each object delegated to at most one waiting client.
		*/
		ref_ptr<GTN_I_MessageQueue> CreateMessageQueue();

		/*
		**  Windows specific
		*/
		
		/*
		** Create a signal based on an existing 'HANDLE' created by 'CreateEvent'.  The handle
		** is duplicated from 'signal', so the caller retains ownership of the handle.
		*/
		ref_ptr<GTN_I_Signal>    CreateSignal( HANDLE signal );
		
		/*
		** Create a signal that is in a signalled state if there is an event in the message queue
		** of the thread blocking on the signal.
		*/
		ref_ptr<GTN_I_Signal>    CreateOSEventSignal();

		bool WaitOnSignalOrEvent( const ref_ptr<GTN_I_Signal> &wait_signal, const SyncWaitAbortDesc *abort_desc );
			// Wait until 'wait_signal' is signaled or an operating system event is available.
	};
	
	class SynchronizationObject
	{
	protected:
		HANDLE fHandle;
	private:
		SynchronizationObject( const SynchronizationObject & );
		void operator =( const SynchronizationObject & );
	public:
		SynchronizationObject( HANDLE handle ) : fHandle( handle ) { FailUnless_OS( handle != 0, assertion_EXCEPTION ); }
		~SynchronizationObject() { ::CloseHandle( fHandle ); }

		HANDLE GetHandle() const { return fHandle; }

		static bool WaitOnSignal( ulong num_sync, const HANDLE *sync_objs, DWORD wait_msg_mask, const SyncWaitAbortDesc *abort_desc );
	};
	
	class CriticalSection
	{
	private:
		CRITICAL_SECTION fCriticalSection;
		
		CriticalSection( const CriticalSection & );
		void operator =( const CriticalSection & );
	public:
		CriticalSection()  { ::InitializeCriticalSection( &fCriticalSection ); }
		~CriticalSection() { ::DeleteCriticalSection( &fCriticalSection ); }
		void enter()       { ::EnterCriticalSection( &fCriticalSection ); }
		void leave()       { ::LeaveCriticalSection( &fCriticalSection ); }
// this function, although in the Windows documentation, does not seem to
// be in the header files. so... this is not correct for now.
		bool try_to_enter() { return ::TryEnterCriticalSection( &fCriticalSection ); }
	};

	class Mutex_Auto
	{
	private:
		SynchronizationObject fMutex;
	public:
		Mutex_Auto( bool initial_owner = false, const uncchar *name = NULL )
			: fMutex( (HANDLE) ::CreateMutexW( NULL, initial_owner?TRUE:FALSE, name ) )
		{}
	
		bool try_to_block( double timeout_in ) const
		{
			SyncWaitAbortDesc abort_desc( timeout_in );
			HANDLE wait_handles[1]; wait_handles[0] = fMutex.GetHandle();
			return SynchronizationObject::WaitOnSignal( 1, wait_handles, 0, &abort_desc );
		}
		void block() const
		{
			HANDLE wait_handles[1]; wait_handles[0] = fMutex.GetHandle();
			SynchronizationObject::WaitOnSignal( 1, wait_handles, 0, NULL );
		}
		void release() const
		{
			::ReleaseMutex( fMutex.GetHandle() );
		}
	};

	/*
	** Semaphore
	*/

	class Semaphore_Auto
	{
	private:
		SynchronizationObject fSemaphore;

		Semaphore_Auto( const Semaphore_Auto & );
		void operator =( const Semaphore_Auto & );
	public:
		Semaphore_Auto( ulong init_count, ulong max_count, const uncchar *name = NULL )
			: fSemaphore( (HANDLE) ::CreateSemaphoreW( NULL, init_count, max_count, name ) )
		{}

		void Post( uint how_many = 1 )
		{
			::ReleaseSemaphore( fSemaphore.GetHandle(), how_many, NULL );
		}
		bool Wait( const SyncWaitAbortDesc *abort_desc )
		{
			HANDLE wait_handles[1]; wait_handles[0] = fSemaphore.GetHandle();
			return SynchronizationObject::WaitOnSignal( 1, wait_handles, 0, abort_desc );
		}

		HANDLE GetHandle() const { return fSemaphore.GetHandle(); }
	};

	/*
	** Gate
	**
	**    Stop all threads from proceeding or allow all to proceed
	**
	**  From
	**
	**     http://world.std.com/~jimf/papers/c++sync/c++sync.html
	**
	*/

	class Gate_Auto
	{
	private:
		SynchronizationObject fGate;
	public:
		Gate_Auto()
			: fGate( (HANDLE) ::CreateEvent( NULL, TRUE, FALSE, NULL ) )
		{}

		void Open()     { ::SetEvent( fGate.GetHandle() ); }
		void Close()    { ::ResetEvent( fGate.GetHandle() ); }
		void Release()  { ::PulseEvent( fGate.GetHandle() ); }
		bool Wait( const SyncWaitAbortDesc *abort_desc )
		{
			HANDLE wait_handles[1]; wait_handles[0] = fGate.GetHandle();
			return SynchronizationObject::WaitOnSignal( 1, wait_handles, 0, abort_desc );
		}
	};
	
} }

#endif // _GATAN_OS_WIN32

#ifdef _GATAN_OS_MACOS

#include <CoreServices/CoreServices.h>

namespace Gatan { namespace Macintosh
{
	class Mac_SynchronizationUtility
	{
	public:
		static Duration calc_duration_from_seconds( double float_timeout_s )
		{
			Duration mac_duration = kDurationForever;

			// !!!!!! Should do something in case of overflow
			if ( float_timeout_s == 0 )
			{
				mac_duration = kDurationImmediate;
			}
			else if ( float_timeout_s == std::numeric_limits<double>::infinity() )
			{
				mac_duration = kDurationForever;
			}
			else if ( float_timeout_s >= 0.001 )		// More than 1 millisecond, use kDurationMillisecnds
			{
				mac_duration = kDurationMillisecond * ( (sint32) std::ceil( float_timeout_s * 1000.0 ) );
			}
			else
			{
				mac_duration = kDurationMicrosecond * ( (sint32) std::ceil( float_timeout_s * 1000000.0 ) );
			}

			return mac_duration;
		}
	};

	class InterlockedRefCount
	{
	public:
		typedef Gatan::ulong count_type;
	private:
		Gatan::ulong ref_count;
	public:
		InterlockedRefCount() : ref_count(0) {}
		InterlockedRefCount( const InterlockedRefCount & ) : ref_count(0) {}
		InterlockedRefCount &operator =( const InterlockedRefCount & ) { return *this; }
		Gatan::ulong addRef() const { return (*const_cast<Gatan::ulong *>( &ref_count ))++; }
		Gatan::ulong remRef() const { return --(*const_cast<Gatan::ulong *>( &ref_count )); }
		Gatan::ulong numRef() const { return ref_count; }
	};

	class InterlockedAmount
	{
	public:
		typedef ulong AmountType;
	private:
		AmountType amount;
	public:
		InterlockedAmount() : amount( 0 ) {}
		inline AmountType inc()    { return amount++; }
		inline AmountType dec()    { return --amount; }
		inline ulong val() const { return amount; }
		inline AmountType exchange_add( long inc ) { AmountType ret = amount; amount += inc; return ret; }
		inline AmountType exchange( long new_val ) { AmountType ret = amount; amount = new_val; return ret; }

		static inline AmountType inc_val( AmountType &val ) { return val++; }
		static inline AmountType dec_val( AmountType &val ) { return --val; }
		static inline AmountType exchange_add_val( AmountType &val, long inc ) { AmountType ret = val; val += inc; return ret; }
		static inline AmountType exchange_val( AmountType &val, long new_val ) { AmountType ret = val; val = new_val; return ret; }
	};

	class Interlock
	{
	public:
		Interlock() : interlock( 0 ) {}
	
		bool acquire()
		{
			bool acquired = false;
			if ( interlock == 0 ) { interlock = 1; acquired = true; }
			return acquired;
		}
			// try to acquire the interlock

		void clear()
		{
			interlock = 0;
		}
			// clear the interlock.
	private:
		long interlock;
	};

	class Synchronization
	{
	public:
		Synchronization();
		~Synchronization();
		
		ref_ptr<GTN_I_Blockable> CreateMutex( bool initial_owner, const uncchar *name );
		ref_ptr<GTN_I_Blockable> CreateSemaphore( ulong initial_count, ulong max_count );
		ref_ptr<GTN_I_Signal>    CreateCancelSignal();
		ref_ptr<GTN_I_Signal>    CreateSignal( bool initially_signalled );
		ref_ptr<GTN_I_MessageQueue> CreateMessageQueue();

		bool WaitOnSignalOrEvent( const ref_ptr<GTN_I_Signal> &wait_signal, const SyncWaitAbortDesc *abort_desc );
			// Wait until 'wait_signal' is signaled or an operating system event is available.
	};

	class Mac_CriticalRegion
	{
	private:
		MPCriticalRegionID   critical_region_id;
	private:
		Mac_CriticalRegion( const Mac_CriticalRegion & );
		void operator =( const Mac_CriticalRegion & );
	public:
		Mac_CriticalRegion()
			:  critical_region_id( NULL )
		{
			FailIfError_OSStatus( MPCreateCriticalRegion( & critical_region_id ), assertion_EXCEPTION );
		}

		~Mac_CriticalRegion()
		{
			FailIfError_OSStatus( MPDeleteCriticalRegion(  critical_region_id ), assertion_CONTINUE );
		}
		
		bool enter_timed( Duration timeout ) const
		{
			OSStatus status = MPEnterCriticalRegion(  critical_region_id, timeout );
			if ( ( status != noErr ) && ( status != kMPTimeoutErr ) ) { FailIfError_OSStatus( status, assertion_EXCEPTION ); }
			return ( status == noErr );
		}

		void leave() const
		{
			FailIfError_OSStatus( MPExitCriticalRegion(  critical_region_id ), assertion_CONTINUE );
		}
	};

	class CriticalSection
	{
	private:
		Mac_CriticalRegion  fCriticalSection;
	private:
		CriticalSection( const CriticalSection & );
		void operator =( const CriticalSection & );
	public:
		CriticalSection() {}
		~CriticalSection() {}

		void enter()
		{
			fCriticalSection.enter_timed( kDurationForever );
		}

		void leave()
		{
			fCriticalSection.leave();
		}

		bool try_to_enter()
		{
			return fCriticalSection.enter_timed( kDurationImmediate );
		}
	};

	class Mutex_Auto
	{
	private:
		Mac_CriticalRegion fCriticalSection;
	public:
		Mutex_Auto( bool initial_owner )
			: fCriticalSection()
		{
			fCriticalSection.enter_timed( kDurationForever );
		}
	
		bool try_to_block( double timeout ) const
		{
			Duration timeout_duration = Mac_SynchronizationUtility::calc_duration_from_seconds( timeout );
			return fCriticalSection.enter_timed( timeout_duration );
		}
		void block() const   { fCriticalSection.enter_timed( kDurationForever ); }
		void release() const { fCriticalSection.leave(); }
	};


	/*
	** Gate
	**
	**    Stop all threads from proceeding or allow all to proceed
	**
    ** !!!!!!!!!!!!!! Implement
	*/

	class Gate_Auto
	{
	private:
	public:
		Gate_Auto()
		{}

		void Open()     {  }
		void Close()    {  }
		void Release()  {  }
		bool Wait( const SyncWaitAbortDesc *abort_desc )
		{
            return true;
		}
	};
} }

#endif // _GATAN_OS_MACOS

namespace Gatan
{
	OS::Synchronization &GFGetSystemSynchronization();

	class BlockableBlocker
	{
	private:
		ref_ptr<GTN_I_Blockable> fBlockable;
		bool                               fIsBlocked;
	public:
		BlockableBlocker( const ref_ptr<GTN_I_Blockable> &blockable )
			: fBlockable( blockable ) , fIsBlocked( false )
		{
			block();
		}
		BlockableBlocker( const ref_ptr<GTN_I_Blockable> &blockable, double timeout )
			: fBlockable( blockable ) , fIsBlocked( false )
		{
			try_to_block( timeout );
		}
		BlockableBlocker( BlockableBlocker &b2 )
			: fBlockable( b2.fBlockable )
			, fIsBlocked( b2.fIsBlocked )
		{
			b2.fIsBlocked = false;
		}
		BlockableBlocker &operator =( BlockableBlocker &b2 )
		{
			fBlockable = b2.fBlockable;
			fIsBlocked = b2.fIsBlocked;
			b2.fIsBlocked = false;
			return *this;
		}
		~BlockableBlocker()
		{
			release();
		}

		bool is_blocked() const { return fIsBlocked; }
		bool try_to_block( double timeout )   { if ( ( fBlockable != NULL ) && !fIsBlocked ) { fIsBlocked = fBlockable->Acquire( timeout ); } return fIsBlocked; }
		void block()   { if ( ( fBlockable != NULL ) && !fIsBlocked ) { fBlockable->Acquire(); fIsBlocked = true; } }
		void release() { if ( ( fBlockable != NULL ) &&  fIsBlocked ) { fBlockable->Release(); fIsBlocked = false; } }
	};

	typedef Gatan::OS::Interlock           Interlock;
	typedef Gatan::OS::InterlockedRefCount InterlockedRefCount;
	typedef Gatan::OS::CriticalSection     CriticalSection;

	class InterlockedAmount   : public Gatan::OS::InterlockedAmount
	{
	public:
		void operator++()    { inc(); }
		void operator++(int) { inc(); }
		void operator--()    { dec(); }
		void operator--(int) { dec(); }
	
		operator ulong() const { return val(); }
	};


	class SynchronizedSection
	{
	public:
		SynchronizedSection( CriticalSection &crit_sect_ )
			: crit_sect( crit_sect_ ), is_in_critical_section( false )
		{
			enter();
		}
	
		~SynchronizedSection()
		{
			leave();
		}
	
		void enter() { if ( !is_in_critical_section ) { crit_sect.enter(); is_in_critical_section = true; } }
		void leave() { if ( is_in_critical_section )  { crit_sect.leave(); is_in_critical_section = false; } }

	private:
		CriticalSection &crit_sect;
		bool             is_in_critical_section;
	};

	typedef OS::Mutex_Auto Mutex;

	class MutexBlocker
	{
	private:
		const Mutex     *fMutex;
		bool             fIsBlocked;

		MutexBlocker( MutexBlocker &b2 );
		MutexBlocker &operator =( MutexBlocker &b2 );
	public:
		MutexBlocker( const Mutex &mutex )
			: fMutex( &mutex ) , fIsBlocked( false )
		{
			block();
		}
		MutexBlocker( const Mutex &mutex, double timeout )
			: fMutex( &mutex ) , fIsBlocked( false )
		{
			try_to_block( timeout );
		}
		~MutexBlocker()
		{
			release();
		}

		bool is_blocked() const { return fIsBlocked; }
		bool try_to_block( double timeout )   { if ( ( fMutex != NULL ) && !fIsBlocked ) { fIsBlocked = fMutex->try_to_block( timeout ); } return fIsBlocked; }
		void block()   { if ( ( fMutex != NULL ) && !fIsBlocked ) { fMutex->block(); fIsBlocked = true; } }
		void release() { if ( ( fMutex != NULL ) &&  fIsBlocked ) { fMutex->release(); fIsBlocked = false; } }
	};
} // namespace Gatan

typedef Gatan::InterlockedRefCount GFInterlockedRefCount;
typedef Gatan::CriticalSection     GFCriticalSection;
typedef Gatan::InterlockedAmount   GFInterlockedAmount;
typedef Gatan::SynchronizedSection GFSynchronizedSection;
typedef Gatan::CriticalSection     GFMonitor;
typedef Gatan::Mutex               GFMutex;
typedef Gatan::MutexBlocker        GFMutexBlocker;

namespace Gatan
{

	gtn_force_inline void ref_ptr_add_ref( GFInterlockedRefCount *ptr )
	{
		if ( ptr != NULL ) { ptr->addRef(); }
	}
	gtn_force_inline uint32 ref_ptr_rem_ref( GFInterlockedRefCount *ptr )
	{
		return ( ptr == NULL ) ? 1 : ptr->remRef();
	}
	gtn_force_inline uint32 ref_ptr_num_ref( GFInterlockedRefCount *ptr )
	{
		return ( ptr == NULL ) ? 0 : ptr->numRef();
	}

/*
** std_final_class_ref_count<FinalObj,RefCount>
**
**    - BaseObj derives from this
**    - classes must not derive from 'FinalObj'
**    - reference counted using 'RefCount'
**    - allocated using 'new' or 'delete' on 'FinalObj'
*/
template <typename FinalObj,typename RefCount = GFInterlockedRefCount>
	struct std_final_class_ref_count
		: public ref_ptr_std_base<FinalObj,RefCount>
	{};

/*
** std_base_class_ref_count<BaseObj,RefCount>
**
**    - BaseObj derives from this
**    - classes are expected to derive from 'BaseObj' ( it must have a virtual destructor )
**    - reference counted using 'RefCount'
**    - allocated using 'new' or 'delete' on 'BaseObj'
*/
template <typename BaseObj,typename RefCount = GFInterlockedRefCount>
	struct std_base_class_ref_count
		: public ref_ptr_std_base<BaseObj,RefCount>
	{};

/*
** std_final_class_ref_count_custom_delete<FinalObj,RefCount>
**
**    - FinalObj derives from this
**    - classes must not derive from 'FinalObj'
**    - reference counted using 'RefCount'
**    - uses custom defined 'ref_ptr_delete'
*/
template <typename FinalObj,typename RefCount = GFInterlockedRefCount>
	struct std_final_class_ref_count_custom_delete
		: public RefCount
	{};

/*
** std_base_class_ref_count_custom_delete<BaseObj,RefCount>
**
**    - BaseObj derives from this
**    - classes are expected to derive from 'BaseObj' ( it must have a virtual destructor )
**    - reference counted using 'RefCount'
**    - uses custom defined 'ref_ptr_delete'
*/
template <typename BaseObj,typename RefCount = GFInterlockedRefCount>
	struct std_base_class_ref_count_custom_delete
		: public RefCount
	{};
}

#endif // __GATANSYNCHRONIZATION__

