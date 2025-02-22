# !/bin/bash
echo "compile small demo"

folder="./output"

if [ ! -d "$folder" ]; then
    mkdir "$folder"
    echo "Folder $folder created."
fi

if [ $# -ne 2 ]; then
    echo "Usage: $0 <source_file> <output_file>"
    exit 1
fi

# 传入两个参数用于编译
echo "Compiling $1 to $folder/$2"
g++ -std=c++17 $1 -o "$folder"/$2

if [ $? -eq 0 ]; then
    echo "Compilation successful: $folder/$2"
else
    echo "Compilation failed"
fi
echo "Output: "

./"$folder"/$2