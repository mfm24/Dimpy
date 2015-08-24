import os
import sys

for inpath in sys.argv[1:]:
	print "Processing:", inpath
	outpath = "_edit".join(os.path.splitext(inpath))
	assert outpath != inpath
	with open(inpath, "rb") as inf:
		data=inf.read();

	data=data.replace("?UUIMPUQ_RegisteR@_facet_basE@stD@@QAEXXZ", "__imp_?_Register@facet@locale@std@@QAEXXZ")
	data=data.replace("?GetcaT@_stdctype_basE@stD@@SAIPAPBVfacet@locale@std@@@Z", "__imp_?_Getcat@?$ctype@_W@std@@SAIPAPBVfacet@locale@2@@Z")

	for rep in ["std", "_base", "_Xlen", "_Xran", "_AddStd", "_Register", "_Getcat", "ios_base", "_Addstd"]:
		data = data.replace(rep[0:-1]+rep[-1].upper(), rep)
	with open(outpath, 'wb') as outf:
		outf.write(data)
	print "Written to", outpath

	