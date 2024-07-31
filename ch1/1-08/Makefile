all: cs test

cs: countspace.c
	gcc countspace.c -o cs

# add verbose flag to test.sh to see output
test: cs 0spaces.txt 10spaceswithtabs.txt 20spaces.txt 60spaces.txt
	./test.sh

clean:
	rm cs
