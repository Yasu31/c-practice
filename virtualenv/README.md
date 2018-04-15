# virtualenv
see where *pip* installs packages by;
```
>>> site.getsitepackages()
['/usr/local/lib/python2.7/dist-packages', '/usr/lib/python2.7/dist-packages']
```
```
(cv) yasu@yasu-ThinkPad-T440s:~/opencv-3.4.1/build$ which python
/home/yasu/.virtualenvs/cv/bin/python
```

>When Python is starting up, it looks at the path of its binary (which, in a virtual environment, is actually just a copy of, or symlink to, your system’s Python binary). It then sets the location of sys.prefix and sys.exec_prefix based on this location, omitting the “bin” portion of the path.
The path located in sys.prefix is then used for locating the “site-packages” directory by searching the relative path lib/pythonX.X/site-packages/, where X.X is the version of Python you’re using.


* [virtualenv user guide](https://virtualenv.pypa.io/en/stable/userguide/)
* [Python Virtual Environments – A Primer](https://realpython.com/python-virtual-environments-a-primer/)
