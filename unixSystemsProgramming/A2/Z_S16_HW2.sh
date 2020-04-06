#Opportunities to program scripts in UNIX
#NAME:Dillon Kern
#Serial Number/S:16
#CS 4350–Unix Systems Programming
#Assignment Number:2
#Due Date:2/24/2020
#Opportunities to program scripts in UNIX
#!/bin/sh

cd "$1"

echo "=============================================="
if  [ $(id -u) = 501 ]; then

   echo "Running as user 501"
else
  echo "Running as guest"
fi
sleep 2

dirCount ()
{
cd "$1" || exit
file=0
dir=0
echo "=============================================="
echo "File and Directory Information"
echo

for d in *
do  
    if [ -d "$d" ]; then
        dir=$((dir+1))
    else
        file=$((file+1))
        fi
done
echo "Directories: $dir"
echo "Files: $file"
sleep 2
}

txtCount ()
{
cd "$1" || exit
txt=0;
for i in ./*.txt
do
    txt=$((txt+1))
done
echo "=============================================="
echo "Of those files, $txt are .txt files"
echo "=============================================="
sleep 2
}

passWord()
{
cd "$1" || exit
        if [[ $1 -ge 8 ]]; then
          echo "$1" | grep -q [0-9]
        if [ $1 -eq 0 ]; then
           echo "$1" | grep -q [A-Z]
        if [ $1 -eq 0 ]; then
           echo "$1" | grep -q [a-z]
        if [ $1 -eq 0 ]; then
                       echo "Strong Password"
                                   else
                echo "Weak Password -> Should include a lower case letter."
                   fi
            else
               echo "Weak Password -> Should include a capital case letter."
            fi
     else
       echo "Weak Password -> Should use numbers in your password."
     fi
else
    echo "Weak Password -> Password length should have at least 8 characters."
fi
}
dirCount
txtCount
passWord

echo "=============================================="
echo "        Names of Empty Subdirectories"

#maxdepth makes find NONRECURSIVE
find $1 -maxdepth 1 -type d -empty > output.txt
cat output.txt
sleep 1
echo "Writing to Output file...."
sleep 1

echo "Done"

echo "=============================================="
sleep 1
echo $1 | rev
echo "whoa... ^"
echo "=============================================="

exit 0

#Implemented by Dillon Kern-­‐2–24–2020
