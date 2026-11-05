$5!="cbr" {next}
$1=="+" && !s[$12]++ {sent++}
$1=="d" {drop++}
$1=="r" && $4==5 && !r[$12]++ {n++; b+=$6; if (!f) f=$2; l=$2}
END {print "Sent:", sent+0, " Received:", n+0, " Dropped:", drop+0
     print "Throughput:", (l>f ? b*8/(l-f)/1000000 : 0), "Mbps"}
