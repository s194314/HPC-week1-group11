module load gprofng
#SIZES="20 40 60 80 100 200 400 600 800 1000 1200 1400 1600"

SIZES="200"
FUNCTIONS="mnk mkn nmk nkm kmn knm"
ITERATION=10

for F in $FUNCTIONS; do
  NAME="file_${F}"
  TEXT_F_NAME="${NAME}.text"
  rm -rf "$TEXT_F_NAME"

  for S in $SIZES; do
    echo -e "Size: {$S}\n" >>"$TEXT_F_NAME"

    C1H=0
    C1M=0
    C2H=0
    C2M=0
    C3H=0
    C3M=0

    for ((i = 0; i < $ITERATION; i++)); do
      FILE_NAME="${NAME}_${S}_${i}.er"
      gprofng collect app -o "$FILE_NAME" -h dch,on,dcm,on,l2h,on,l2m,on,l3h,on,l3m,on ./matmult_c.gcc "$F" $S $S $S

      C1H=$((C1H + $(gprofng display text -functions "$FILE_NAME" | grep "<Total>" | awk '{print $5}')))
      C1M=$((C1M + $(gprofng display text -functions "$FILE_NAME" | grep "<Total>" | awk '{print $7}')))

      C2H=$((C2H + $(gprofng display text -functions "$FILE_NAME" | grep "<Total>" | awk '{print $9}')))
      C2M=$((C2M + $(gprofng display text -functions "$FILE_NAME" | grep "<Total>" | awk '{print $11}')))

      C3H=$((C3H + $(gprofng display text -functions "$FILE_NAME" | grep "<Total>" | awk '{print $13}')))
      C3M=$((C3M + $(gprofng display text -functions "$FILE_NAME" | grep "<Total>" | awk '{print $15}')))

      gprofng display text -functions "$FILE_NAME" >>"$TEXT_F_NAME"
    done

    C1H=$(echo "$C1H / $ITERATION" | bc -l)
    C1M=$(echo "$C1M / $ITERATION" | bc -l)
    C2H=$(echo "$C2H / $ITERATION" | bc -l)
    C2M=$(echo "$C2M / $ITERATION" | bc -l)
    C3H=$(echo "$C3H / $ITERATION" | bc -l)
    C3M=$(echo "$C3M / $ITERATION" | bc -l)

    FN="average$$.text"
    echo -e "Function: ${F}, Dimensions: ${S}, Repetitions: ${ITERATION}" >> $FN
    echo -e "L1-hit: ${C1H}, L1-miss: ${C1M}, L2-hit: ${C2H}, L2-miss: ${C2M}, L3-hit: ${C3H}, L3-miss: ${C3M}\n" >> $FN

  done
done

rm -rf *.er
