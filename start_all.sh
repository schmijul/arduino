#!/bin/bash
green=`tput setaf 2`
reset=`tput sgr0`
sudo sh ltestop.sh
sudo sh ltestart.sh
sleep 2
echo "${green} lte-connection established  ${reset}"
pidof sh ltesart.sh

sh gps.sh &
sleep 2
echo "${green} gps-meassurement started  ${reset}"
gps=$(pidof -s sh gps.sh)

sh ping.sh &
sleep 2 
echo "${green} ping-meassurement started ${reset}"
ping=$(pidof -s sh ping.sh)





gnome-terminal -- python3 monitor-mobileinsight-and-timefix.py /dev/ttyUSB0 9600
sleep 2
echo "${green} mobileinsight-meassurement started ${reset} "
mobileinsight=$(pidof -s python3 monitor-mobileinsight-and-timefix.py)


sh tcpdump.sh &

pcap=$(pidof -s tcpdump)

echo "${green}  choose iperf_meassurement ${reset}"

read a

cd iperf_scripts/testdrive_2/


gnome-terminal -- python3 iperf_scheduler.py $a
sleep 2
echo "${green} iperf-meassurement $1 started  ${reset}"
iperf=$(pidof -s python3 iperf_scripts/iperf_scheduler.py $a)

sleep 8
echo {$gps,$ping,$pcap,$mobileinsight,$iperf}



sleep 3
watch ps -p {$gps,$ping,$pcap,$mobileinsight,$iperf}



