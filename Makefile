final:
	gcc cat.c -o cat.out
	gcc ls.c -o ls.out
	gcc ls-a.c -o ls-a.out
	gcc ls-aA.c -o ls-aA.out
	gcc date.c -o date.out
	gcc date-R.c -o date-R.out
	gcc date-I.c -o date-I.out
	gcc rm.c -o rm.out
	gcc mkdir.c -o mkdir.out
	gcc mkdir-p.c -o mkdir-p.out
	gcc internalCommand.c -o intern.out
	./intern.out