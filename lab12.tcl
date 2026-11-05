set ns [new Simulator]
$ns trace-all [set tf [open lab12.tr w]]
$ns namtrace-all [set nf [open lab12.nam w]]
$ns color 1 red; $ns color 2 blue
for {set i 0} {$i < 4} {incr i} {set n$i [$ns node]}
$ns duplex-link $n0 $n2 100Mb 1ms DropTail
$ns duplex-link $n1 $n2 100Mb 1ms DropTail
$ns duplex-link $n2 $n3 100Mb 1ms DropTail
set tcp [$ns create-connection TCP $n0 TCPSink $n3 1]
$tcp set packetSize_ 500
set ftp [$tcp attach-app FTP]
set cbr [[$ns create-connection UDP $n1 Null $n3 2] attach-app Traffic/CBR]
$cbr set packetSize_ 500
$cbr set interval_ 0.001                     ;# vary
proc finish {} {
    global ns tf nf
    $ns flush-trace; close $tf; close $nf
    exec nam lab12.nam &
    exit 0
}
$ns at 0.1 "$cbr start"
$ns at 0.2 "$ftp start"
$ns at 5.0 finish
$ns run
