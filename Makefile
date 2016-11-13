julia: julia.c
	gcc -o julia main.c -lm

clean:
	rm julia
