Just A simple and lightweight TUI app for managing Sparx bookworks

This was mostly a proof of concept and is very, very buggy and I have already spent longer than I intended to on this **very** useless project. Also this is my first major C project so please don't judge to much :)

Haven't built in non-unix support so won't work on Windows

This requires no dependencies so you just compile without linking (e.g. gcc main.c -o Main when the source code is in the active directory, you can copy the whole directory with a git clone) 

Will need to set the save directory at /home/usrname/.bookwork/.save_dir_file.txt as the program will not assume the directory (for the program to work the file must contain one line in the form /path/to/dir/ without the use of ~/ or ./)

#How to play
* Compile from source or download from the [https://github.com/noahhartmanuk-cmd/No_More_Bookwork/releases](Releases Page)
* Run the program with ./Main
* Type h to show options
* Enjoy!
