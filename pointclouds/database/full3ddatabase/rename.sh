 i=0;
for file in *.3DS;
do 
	let i=i+1; 
	k=`printf %03d $i`; 
	mv "$file" 3d_u"$k".off; 
done
