
module load gprofng


#SIZES="20 40 60 80 100 200 400 600 800 1000 1200 1400 1600"

SIZES="100"
FUNCTIONS="mnk mkn nmk nkm kmn knm"

for F in $FUNCTIONS; do
  NAME="file_${F}"
  TEXT_F_NAME="${NAME}.text"
  rm -rf "$TEXT_F_NAME"


  for (( i = 0; i < 5; i++ )); do

  done

  for S in $SIZES; do
    echo -e "Size: {$S}\n" >> "$TEXT_F_NAME"
    FILE_NAME="${NAME}_${S}.er"
    gprofng collect app -o "$FILE_NAME" -h dch,on,dcm,on,l2h,on,l2m,on,l3h,on,l3m,on ./matmult_c.gcc "$F" $S $S $S
    C1H=$(gprofng display text -functions file3.er | grep "<Total>" | awk '{print $5}')
    gprofng display text -functions "$FILE_NAME" >> "$TEXT_F_NAME"

  done
done
