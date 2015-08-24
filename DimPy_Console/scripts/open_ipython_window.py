import logging
logging.basicConfig()
import gettext


try:
    ok = True
    from IPython.qt.console.rich_ipython_widget import RichIPythonWidget
    from IPython.qt.inprocess import QtInProcessKernelManager
    from IPython.lib import guisupport
except ImportError:
    ok = False
except NameError:
    ok = False


def show_ipython_console():
    # from https://github.com/ipython/ipython/blob/1.x/examples/inprocess/embedded_qtconsole.py
    # this might be able to be a dockable panel at some point in the future.
    # it should also only allow one window open at a time - I think it steals stdout at start
    # and opening a new window stops output working on the old one!
    app = guisupport.get_app_qt4()

    # Create an in-process kernel
    # >>> print_process_id()
    # will print the same process ID as the main process
    kernel_manager = QtInProcessKernelManager()
    kernel_manager.start_kernel()
    kernel = kernel_manager.kernel
    kernel.gui = 'qt4'

    kernel_client = kernel_manager.client()
    kernel_client.start_channels()

    def stop():
        kernel_client.stop_channels()
        kernel_manager.shutdown_kernel()
        app.exit()

    control = RichIPythonWidget()
    control.kernel_manager = kernel_manager
    control.kernel_client = kernel_client
    control.exit_requested.connect(stop)
    control.show()

    guisupport.start_event_loop_qt4(app)

print "something"
if ok:
    show_ipython_console()
else:
    logging.info("Couldn't load IPythonConsole plugin. Probably IPython or PySide/PyQt is missing!")
    print "yep"