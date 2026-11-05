set ns [new Simulator]
$ns trace-all [set tf [open lab13.tr w]]
$ns namtrace-all [set nf [open lab13.nam w]]
$ns color 1 blue; $ns color 2 orange
for {set i 0} {$i < 6} {incr i} {set n$i [$ns node]}
foreach {a b} "$n0 $n2 $n1 $n2 $n2 $n3 $n3 $n4 $n3 $n5" {$ns duplex-link $a $b 0.5Mb 10ms DropTail}
Agent/Ping set packetSize_ 500
set p0 [$ns create-connection Ping $n0 Ping $n4 1]
set p1 [$ns create-connection Ping $n1 Ping $n5 2]
set cbr [[$ns create-connection UDP $n0 Null $n4 0] attach-app Traffic/CBR]
$cbr set packetSize_ 512
$cbr set interval_ 0.001
Agent/Ping instproc recv {from rtt} {
    $self instvar node_
    puts "The node [$node_ id] received a reply from $from with round trip time of $rtt ms"
}
proc finish {} {
    global ns tf nf
    $ns flush-trace; close $tf; close $nf
    exec nam lab13.nam &
    exit 0
}
foreach t {0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0} {$ns at $t "$p0 send; $p1 send"}
$ns at 0.2 "$cbr start"
$ns at 4.0 "$cbr stop"
$ns at 5.5 finish
$ns run
