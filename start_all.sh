#!/bin/bash


sh ltestart.sh
sleep 2
echo "lte-connection established "
pidof sh ltesart.sh

sh gps.sh &
sleep 2
echo "gps-meassurement started "
gps=$pidof (sh gps.sh)

sh ping.sh &
sleep 2
echo "ping-meassurement started "
ping=$(pidof sh ping.sh)

python3 monitor-mobileinsight-and-timefix.py /dev/ttyUSB0 9600 &
sleep 2
echo "mobileinsight-meassurement started "
mobileinsight=$(pidof python3 monitor-mobileinsight-and-timefix.py /dev/ttyUSB0 9600)




gnome-terminal --tab --title="iperf" --command="bash -c 'python3 iperf_scripts/iperf_scheduler.py $1 &'i"
sleep 2
echo"iperf-meassurement $1 started "
iperf=$(pidof python3 iperf_scripts/iperf_scheduler.py $1)

watch ps -p {$gps,$ping,$mobileinsight,$iperf}

