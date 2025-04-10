int=$#
str=""
if [ $# -eq 0 ]
then  
	echo Usage:phone searchforp[...searchfor]
	   echo "(You didn't tell me what you want to search for.)"
fi

for arg in "$@"
do
	if [ $int -eq $# ]
	then
		str=$(egrep -i "$arg" mydata.txt)
	fi

	if [ -n "$str" ]
	then
		str=$(egrep -i "$str|$arg" mydata.txt)
	fi
	
	int=`expr $int - 1`

	if [ $int -eq 0 ]
	then
		if [ -n "$str" ]
		then
			egrep -i "$str" mydata.txt|awk -f display.awk
		fi
	fi
done

