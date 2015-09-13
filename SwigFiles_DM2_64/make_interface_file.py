# make interface file
# makes the interface file for SWIG from standard DM
# include file
import os
import re
import logging

logging.basicConfig()

# path to sdk folder (this should contain an 'include' folder)
sdk_path = "C:\ProgramData\Gatan\DMSDK"

# we open 'include/DMPluginStubs.h"
out_file = "DMPlugInStubs_modified.h"
in_file = os.path.join(sdk_path, 'include/DMPlugInStubs.h')

def get_signatures(text):
	""" Return signatures found in a block of text. 
	Signatures may extend over line breaks"""
	# convert to a single block
	combined = re.sub("\s+", " ", text)
	# search for all signatures
	return re.findall("\w+ [^(]*\([^)]*\);", combined)
	
def get_function_name(sig):
	""" for a signature like
	ret_type funcname(arg0, arg1)
	returns funcname
	"""
	return re.match("\w+\W+(\w+)", sig).groups()[0]
	

find_funcs = re.compile(r"""
	^/[*]*   # start line with / and any number of *s
	\n       # linefeed
	([^*]*)  # group 0: any non chars after this
	[*]*/    # any amount of *s then /
	\n       # linefeed
	([^/]*)  # group 1, all text up to start of next comment
	""", re.MULTILINE | re.VERBOSE)
	
	
dat = open(in_file, 'rt').read()

with open(out_file, 'wt') as fout:
	head, *matches = find_funcs.split(dat)
	fout.write(head)
	last = matches[-1]
	matches = iter(matches)
	for comment, signatures, after in zip(*[matches]*3):
		for signature in get_signatures(signatures):
			if "..." in signature:
				logging.warn("Ignoring varardic function: %s"
				% signature)
				continue
			func_name = get_function_name(signature)
			fout.write('%feature("docstring") {} \n"{}";\n'.format(
				func_name, comment.strip()))
			fout.write(signature + "\n\n")
			# print(func_name)
	# file starts with a namespace Gatan { namespace DM { 
	fout.write("}\n}\n")
	# file starts with a 
	# #ifndef _GATAN_PLUGIN_DIGITALMICROGRAPH_FUNCTIONS 
	# that we should terminate
	fout.write("#endif // _GATAN_PLUGIN_DIGITALMICROGRAPH_FUNCTIONS\n")