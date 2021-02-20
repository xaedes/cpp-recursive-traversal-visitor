
cat readme.txt  | grep "recursive counting" -B 1 -A 15 | sed -r "s/^.+(string|int)$/\1/" | sed -r "s/\s+iterate recursive counting\s+//" | sed -r "s/^\.\.\\\\.+$//" | egrep -v -x "\-+" | egrep -v -x "\.\.+" | egrep -v -x "\s*(benchmark|mean|std dev).+" | sed -r "s/^\s+([^\s]+\s\w\w).+$/\1/" | sed -r "s/::visit.+$//" | tr "\n" "@" | sed -r "s/(string|int)@\[(N=[0-9]+)\]/\2 \1/g" | sed -r "s/@@@?/@/g" | tr "@" " " | sed -r "s/(N=)/@\1/g" | tr "@" "\n"