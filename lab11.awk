$1=="+" && ($3==0 || $3==1) {s++}
$1=="d" {d++}
END {print "Packets sent:", s+0; print "Packets dropped:", d+0}
