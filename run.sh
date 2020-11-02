#!/bin/sh

# running over multiple variables
# program takes 6 inputs to work:
# 1) filename
# 2) cN
# 3) cS
# 4) cP
# 5) MS
# 6) MP

rm ./data/*.txt
make 

declare -a cNrange=(10 20 50 100 250)
declare -a cSrange=(10 20 50 100)
declare -a cPrange=(10 20 50 100 250)
declare -a MSrange=(10 20 30 50 100)
declare -a MPrange=(10 20 30 50 100)

N=$1
for cN in "${cNrange[@]}"
do
	for cS in "${cSrange[@]}"
	do
		for cP in "${cPrange[@]}"
		do
			for MS in "${MSrange[@]}"
			do
				for MP in "${MPrange[@]}"
				do
					((i=i%N)); ((i++==0)) && wait
					filename=cN=$cN\_cS=$cS\_cP=$cP\_MS=$MS\_MP=$MP
					./ode $filename $cN $cS $cP $MS $MP &
				done
			done
		done
	done
done
