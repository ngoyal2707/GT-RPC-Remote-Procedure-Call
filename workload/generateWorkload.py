import random
random.seed(0)

with open('distinctURLs.txt') as fin:
	URLS = []
	for line in fin:
		URLS.append(line.strip())
	randomURLS = []

	for i in xrange(150):
		print URLS[random.randint(0,len(URLS)-1)]
