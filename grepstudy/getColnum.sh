grep -E -n "$1" $3 | sed -E -e s/:.*// -n -e $2p
