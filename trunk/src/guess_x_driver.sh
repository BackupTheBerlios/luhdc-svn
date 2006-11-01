#!/bin/bash

DRV=$(grep -i -A 30 "Section.\+\"Device\"" /etc/X11/xorg.conf|grep -m1 Driver|sed s/"^.\+driver"/""/gi)
GXDRIVER=$(echo $DRV|sed s/" \+"/""/g|sed s/"\""/""/g)
MPATHS=$(grep module /etc/X11/xorg.conf|sed  s/"modulepath"/""/gi|sed s/"\""/""/g)
MPATHS="/usr/lib/xorg/modules $MPATHS"
for i in $MPATHS
do
  #echo "$i/drivers/${GXDRIVER}_drv.so"
  if [ -f $i/drivers/${GXDRIVER}_drv.so ]
  then
     GXDLOC=$i/drivers/${GXDRIVER}_drv.so
     #echo "Driver located at :" $GXDLOC
     break
  fi
done
if [ ! -z "$GXDLOC" ]
then
  if [ -z "$1" ]
  then
    PAK=$(dpkg -S $GXDLOC|cut -f1 -d":")
    PAKVER=$(dpkg -l|grep $PAK|sed s/" \+"/" "/g|cut -f2,3 -d" "|sed s/" "/" version "/g)
    echo "$GXDRIVER (Provided by) $PAKVER"
  else
    echo $GXDRIVER
  fi
fi
