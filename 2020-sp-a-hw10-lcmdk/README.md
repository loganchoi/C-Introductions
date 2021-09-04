# Homework #10 (Final Assignment)

Link to your assignment:
[https://sites.google.com/a/mst.edu/price/courses/cs-1570/hw/2020/spring/assignment-10---final-project](https://sites.google.com/a/mst.edu/price/courses/cs-1570/hw/2020/spring/assignment-10---final-project)

# Group Members: 
If you have a group, list both names in your group above by the heading (Group Members: x, y) ^^^

# Files

You should have multiple files containing a program written in C++.

Make sure you use header files and source files correctly. 

***DO NOT*** write everything in your main file!

Also, please **DO NOT** commit your executable file created after compiling. Only submit your source C++ files.

Also, put all `.cpp`, `.h`, and `.hpp` files in the root of this repository. You should have **NO** `.cpp` or `.h` or `.hpp` files in **ANY** sub-directories. You shouldn't need sub-directories anyways. You should be able to run the compile command below from the root of this repository with no compliation errors.

# Tips

Make sure to compile and test your code before submitting. Also make sure to take the time and see if the output is correct. (Or you'll lose points.)

How to compile!

  - `g++ *.cpp -o name` or `fg++` if you're on a school computer

So `*.cpp` here will be all of your `.cpp` files... obviously (The `*` is a wildcard that grabs all `.cpp` files in the current directory). `name` is an executable. This is the file you use to run your program after it has compiled.

You can call `name` whatever you want: `dog`, `cat`. 

You can also omit `name` by running `g++ *.cpp` or `fg++ *.cpp`. This will generate a file called `a.out`. You can still run this file the same as if you had provided a name. `a.out` is just the default.

**If you get an error that you don't understand.... GOOGLE!!!**

I don't know if you have heard of Google, but it's a pretty amazing tool that can help you find all sorts of information.

If you have C++ questions I'm generally available on the Discord server at [https://discord.gg/2vayFz7](https://discord.gg/2vayFz7)

## Git help

Some of you may not be familiar with git still, so here are the basic steps:
*	Clone the repo using the "clone/download" and copy the link in the `HTTPS` box.
*	Create a `cs1570` folder in your SDRIVE if you don't have one already: `mkdir cs1570` and `cd cs1570` so you're inside the folder.
*	`git clone the-link-you-copied`
*	This should create a folder called `2020-SP-CS1570-hwX`. You can now `cd` into that folder.
*	Whenever you create a new file `git` will track your changes and you can add your file to the repo by doing `git add filename.ext`
*	Now we can "commit" our file! You need to add a message with your commit to briefly explain what your changes are. `git commit -m "Your meaningful commit message"`. The message will show up in your git repo, so be careful of what you write.
*	Finally you can "push" your changes to the git repo! `git push`  is all you need to do, it'll ask you to login with your info so once you login you'll be done.