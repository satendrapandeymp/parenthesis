import os
data = raw_input("type 1 for paste you texts or 2 for give your file location as input:\n")
if int(data) == 1:
	data = raw_input("paste you texts:\n")
	datas = datas.replace("'","")
	datas = datas.replace('"',"")
	cmd = "./parentheses '-%s'"%(data)
	os.system(cmd)
	res = open("test.txt")
	print res.read()
else:
	data = raw_input("paste you absolute file location:\n")
	res = open(data)
	datas = res.read()
	res.close()
	print datas
	datas = datas.replace("'","")
	datas = datas.replace('"',"")
	print datas
	cmd = "./parentheses '-%s'"%(datas)
	os.system(cmd)
	res = open("test.txt")
	print res.read()
res.close()
