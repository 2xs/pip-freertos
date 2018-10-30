#!/bin/sh

IFS=' '

echo "#ifndef _FREERTOS_ACCESS_h"
echo "#define _FREERTOS_ACCESS_h"


while read -ra line || [[ -n "$line" ]]; do

    if [ ${line[1]} = "T" ]; then
        echo -e "#ifndef ${line[2]}"
        echo -e "\t#define ${line[2]} 0x${line[0]}"
        echo -e "#endif\n"
    fi
done < "function_addr.fun"


echo "#endif"
