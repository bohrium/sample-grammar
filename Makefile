moo:
	swig -python moo.i
	python setup.py build
	cp build/*/*.so .

clear:
	rm moo_wrap.c
	rm moo.py
	rm *.so
	rm build/*/*
	rm -r build
	rm __pycache__/*
	rm -r __pycache__
