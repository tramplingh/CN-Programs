$1=="d" {d++; x[$5]++}
END {print "Ping dropped:", x["ping"]+0; print "CBR dropped:", x["cbr"]+0; print "Total dropped due to congestion:", d+0}
