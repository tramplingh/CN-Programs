set ns [new Simulator]
$ns trace-all [set tf [open lab14.tr w]]
$ns namtrace-all [set nf [open lab14.nam w]]
for {set i 0} {$i < 4} {incr i} {lappend L [set n$i [$ns node]]}   ;# vary n
$ns make-lan $L 10Mb 10ms LL Queue/DropTail Mac/802_3
set tcp0 [$ns create-connection TCP $n0 TCPSink $n3 0]
set tcp2 [$ns create-connection TCP $n2 TCPSink $n1 0]
set ftp0 [$tcp0 attach-app FTP]
set ftp2 [$tcp2 attach-app FTP]
$tcp0 set maxcwnd_ 10
$tcp0 attach [set f1 [open file1.tr w]]
$tcp0 trace cwnd_
$tcp2 attach [set f2 [open file2.tr w]]
$tcp2 trace cwnd_
proc finish {} {
    global ns tf nf f1 f2
    $ns flush-trace; close $tf; close $nf; close $f1; close $f2
    exec nam lab14.nam &
    exit 0
}
foreach {t a} {0.1 start 1.5 stop 2 start 3 stop} {$ns at $t "$ftp0 $a"}
foreach {t a} {0.2 start 2 stop 2.5 start 4 stop} {$ns at $t "$ftp2 $a"}
$ns at 5.0 finish
$ns run
