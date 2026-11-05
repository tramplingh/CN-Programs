set ns [new Simulator]
$ns trace-all [set tf [open lab11.tr w]]
$ns namtrace-all [set nf [open lab11.nam w]]
$ns color 1 red; $ns color 2 blue
for {set i 0} {$i < 4} {incr i} {set n$i [$ns node]}
$ns duplex-link $n0 $n2 10Mb 300ms DropTail
$ns duplex-link $n1 $n2 10Mb 300ms DropTail
$ns duplex-link $n2 $n3 1Mb 300ms DropTail   ;# vary bandwidth
$ns queue-limit $n0 $n2 10
$ns queue-limit $n1 $n2 10
$ns queue-limit $n2 $n3 5                    ;# vary queue size
foreach {src c} "$n0 1 $n1 2" {
    set cbr [[$ns create-connection UDP $src Null $n3 $c] attach-app Traffic/CBR]
    $cbr set packetSize_ 500
    $cbr set interval_ 0.005
    $ns at 0.1 "$cbr start"
}
proc finish {} {
    global ns tf nf
    $ns flush-trace; close $tf; close $nf
    exec nam lab11.nam &
    exit 0
}
$ns at 10.0 finish
$ns run
