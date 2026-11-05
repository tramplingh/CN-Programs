$1=="+" && $3==0 && $5=="tcp" {ts++}
$1=="+" && $3==1 && $5=="cbr" {us++}
$1=="r" && $3==2 && $4==3 {if ($5=="tcp") tr++; if ($5=="cbr") ur++}
END {printf "TCP sent %d, received at n3 %d\nUDP sent %d, received at n3 %d\n", ts, tr, us, ur}
