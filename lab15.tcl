set ns [new Simulator]
$ns trace-all [set tf [open lab15.tr w]]
$ns namtrace-all [set nf [open lab15.nam w]]
$ns color 1 red
for {set i 0} {$i < 7} {incr i} {set n$i [$ns node]}
$ns make-lan "$n0 $n1 $n2 $n3" 10Mb 10ms LL Queue/DropTail Mac/802_3
$ns make-lan "$n4 $n5 $n6" 10Mb 10ms LL Queue/DropTail Mac/802_3
$ns duplex-link $n3 $n6 100Mb 10ms DropTail
set cbr [[$ns create-connection UDP $n1 Null $n5 1] attach-app Traffic/CBR]
$cbr set packetSize_ 1000
$cbr set rate_ 80Mb                          ;# vary data rate
set err [new ErrorModel]
$err set rate_ 0.2                           ;# vary error rate
$ns lossmodel $err $n3 $n6
proc finish {} {
    global ns tf nf
    $ns flush-trace; close $tf; close $nf
    exec nam lab15.nam &
    exit 0
}
$ns at 0.1 "$cbr start"
$ns at 5.0 finish
$ns run
