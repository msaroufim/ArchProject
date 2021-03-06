#!/bin/bash
#thanks to Amirasam Memaripour for providing this nice shell script

echo "Compiling source ..."

cd src

make clean

make

cd ..

echo "Providing predictor with traces ..."



FILES=`ls -1 traces`



for f in $FILES

do

        echo "----------------------------------"

        echo "Processing $f ..."

        output=`bunzip2 -c -k "traces/$f" | ./src/predictor`

        index=0

        for line in $output

        do

                last=$line

                let "index=index+1"

                if [ "$index" -eq 2 ]; then

                        echo -e "Branches\t$line"

                elif [ "$index" -eq 4 ]

                then

                        echo -e "Incorrect\t$line"

                fi

        done

        echo -e "Output\t\t$last"

done

exit 0
