COLS=($(grep -n "^--$" log151719.txt|sed -e "s/:.*//") $) #--がある行番号リスト
NUM=${#COLS[@]}
echo ${NUM}個のグループがあります
BEGIN=1
for((i=0;i<${NUM};i++));do
    END=${COLS[$i]}
    sed -n ${BEGIN},${END}p log151719.txt | grep -v "^--$" > ${i}_sep.txt
    BEGIN=${END};
done
