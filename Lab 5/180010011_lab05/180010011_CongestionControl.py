import sys
import random


ki = sys.argv[1]
km = sys.argv[2]
kn = sys.argv[3]
kf = sys.argv[4]
ps = sys.argv[5]
t = sys.argv[6]
ki = float(ki)
km = float(km)
kn = float(kn)
kf = float(kf)
ps = float(ps)
t = int(t)
MSS = 1.0
RWS = 1000
SSThreshold = t/2
i = 0
CW = ki*MSS
cw = 0

z =0
y=0
flag = 2
fptr = open(sys.argv[7],"w")
for i in range(t):
	vc = 0;
	n = CW/MSS + 1
	n = int(n)
	
	j=0
	x = random.uniform(0.0,1.0)
	x = round(x,4)
	
	cw = CW
	for j in range(n) :
		flag =1
		
		if x < ps:
			SSThreshold = CW/2
			CW = max(1, kf*cw)
		else:
			i=i+n
			if CW < SSThreshold:
				CW = min(cw + km*MSS, RWS)
				
			else:
				CW = min(cw + kn*MSS*MSS/cw, RWS)
			
	
	
	
	fptr.write(str(CW) + " for iteration: "+ str(y)+"\n")

	
	y= y+1

#------------------------------------------------------------------------------------------
#Compile: python3 180010011_CongestionControl.py <Ki> <Km> <Kn> <Kf> <Ps> <T> <outputfile>

#TO run for multiple files:
#python3 test1.py 1 1.5 1.0 0.5 0.01 1000 ki_1.txt
#python3 test1.py 2 1.5 1.0 0.5 0.01 1000 ki_2.txt
#python3 test1.py 3 1.5 1.0 0.5 0.01 1000 ki_3.txt
#python3 test1.py 4 1.5 1.0 0.5 0.01 1000 ki_4.txt
#python3 test1.py 3 1.0 1.0 0.25 0.1 1000 km_1.txt
#python3 test1.py 3 1.2 1.0 0.25 0.1 1000 km_2.txt
#python3 test1.py 3 1.3 1.0 0.25 0.1 1000 km_3.txt
#python3 test1.py 3 1.4 1.0 0.25 0.1 1000 km_4.txt
#python3 test1.py 3 1.3 0.6 0.5 0.01 1000 kn_1.txt
#python3 test1.py 3 1.3 0.7 0.5 0.01 1000 kn_2.txt
#python3 test1.py 3 1.3 0.8 0.5 0.01 1000 kn_3.txt
#python3 test1.py 3 1.3 0.9 0.5 0.01 1000 kn_4.txt
#python3 test1.py 3 1.3 1.0 0.1 0.01 1000 kf_1.txt
#python3 test1.py 3 1.3 1.0 0.2 0.01 1000 kf_2.txt
#python3 test1.py 3 1.3 1.0 0.25 0.01 1000 kf_3.txt
#python3 test1.py 3 1.3 1.0 0.3 0.01 1000 kf_4.txt
#python3 test1.py 3 1.3 1.0 0.5 0.01 1000 ps_1.txt
#python3 test1.py 3 1.3 1.0 0.5 0.003 1000 ps_2.txt
#python3 test1.py 3 1.3 1.0 0.5 0.007 1000 ps_3.txt
#python3 test1.py 3 1.3 1.0 0.5 0.0001 1000 ps_4.txt


#After getting all data files, type gnuplot in terminal

#gnuplot> plot 'ki_1.txt' w l, 'ki_2.txt' w l, 'ki_3.txt' w l, 'ki_4.txt' w l
#gnuplot> plot 'km_1.txt' w  l, 'km_2.txt' w l, 'km_3.txt' w  l, 'km_4.txt' w l
#gnuplot> plot 'kn_1.txt' w l, 'kn_2.txt' w l, 'kn_3.txt' w  l, 'kn_4.txt' w l
#gnuplot> plot 'kf_1.txt' w l, 'kf_2.txt' w l, 'kf_3.txt' w l, 'kf_4.txt' w l
#gnuplot> plot 'ps_1.txt' w l, 'ps_2.txt' w l, 'ps_3.txt' w l, 'ps_4.txt' w l
