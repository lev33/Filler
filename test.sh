#!/bin/bash

echo "Results:" > $1
echo " " >> $1
echo "champely.filler" >> $1
./filler_vm -f ./maps/map00 -p1 ./ligeorgi.filler -p2 ./players/champely.filler | tail -n2 >> $1
./filler_vm -f ./maps/map01 -p1 ./ligeorgi.filler -p2 ./players/champely.filler | tail -n2 >> $1
# ./filler_vm -f ./maps/map02 -p1 ./ligeorgi.filler -p2 ./players/champely.filler | tail -n2 >> $1
echo " " >> $1
echo "abanlin.filler" >> $1
./filler_vm -f ./maps/map00 -p1 ./ligeorgi.filler -p2 ./players/abanlin.filler | tail -n2 >> $1
./filler_vm -f ./maps/map01 -p1 ./ligeorgi.filler -p2 ./players/abanlin.filler | tail -n2 >> $1
# ./filler_vm -f ./maps/map02 -p1 ./ligeorgi.filler -p2 ./players/abanlin.filler | tail -n2 >> $1
echo " " >> $1
echo "hcao.filler" >> $1
./filler_vm -f ./maps/map00 -p1 ./ligeorgi.filler -p2 ./players/hcao.filler | tail -n2 >> $1
./filler_vm -f ./maps/map01 -p1 ./ligeorgi.filler -p2 ./players/hcao.filler | tail -n2 >> $1
# ./filler_vm -f ./maps/map02 -p1 ./ligeorgi.filler -p2 ./players/hcao.filler | tail -n2 >> $1
echo " " >> $1
echo "grati.filler" >> $1
./filler_vm -f ./maps/map00 -p1 ./ligeorgi.filler -p2 ./players/grati.filler | tail -n2 >> $1
./filler_vm -f ./maps/map01 -p1 ./ligeorgi.filler -p2 ./players/grati.filler | tail -n2 >> $1
# ./filler_vm -f ./maps/map02 -p1 ./ligeorgi.filler -p2 ./players/grati.filler | tail -n2 >> $1
echo " " >> $1
echo "carli.filler" >> $1
./filler_vm -f ./maps/map00 -p1 ./ligeorgi.filler -p2 ./players/carli.filler | tail -n2 >> $1
./filler_vm -f ./maps/map01 -p1 ./ligeorgi.filler -p2 ./players/carli.filler | tail -n2 >> $1
# ./filler_vm -f ./maps/map02 -p1 ./ligeorgi.filler -p2 ./players/carli.filler | tail -n2 >> $1
echo " " >> $1
echo "superjeannot.filler" >> $1
./filler_vm -f ./maps/map00 -p1 ./ligeorgi.filler -p2 ./players/superjeannot.filler | tail -n2 >> $1
./filler_vm -f ./maps/map01 -p1 ./ligeorgi.filler -p2 ./players/superjeannot.filler | tail -n2 >> $1
# ./filler_vm -f ./maps/map02 -p1 ./ligeorgi.filler -p2 ./players/superjeannot.filler | tail -n2 >> $1

