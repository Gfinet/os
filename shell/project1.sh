c="name.exe"
b="name2.exe"
a="name.c"
com="ls"
ListeMD5=''
Dossiers=""
MD5(){
	ListeLs+=`echo "$var1" | $com $1`
	#echo $ListeLs
	for var in $ListeLs
	do
		if [ -e $var ]
			then
			echo $var
			if [ "$var" != '.*' ]  && [ "$var" != '*/' ] && [ ! -d ${var/".\/"} ]
				then	
				Liste2MD5+=$var" "
				Trad=$(md5sum "$var")
				Trad=${Trad} #%\ * 
				echo $Trad
				ListeMD5+=$Trad" "
			elif [ -d ${var/".\/"} ]
				then
				Modifvar=${var/".\/"}
				dossi="$1/$var"
		    	cd $dossi
				Liste2MD5=`echo "$V" |  MD5 $dossi`
				cd ..
				
			fi
		fi
		
	done
	# echo $1\\$Dossiers
	#for var in $Dossiers
	#do
	#	if [ -d $var ]
	#		then

	#		dossi="$1/$var"
	#	    cd $dossi
	#		`echo "$V" |  MD5 $dossi`
	#echo $ListeMD5
	echo $Liste2MD5
	#		cd ..
	#	fi
	#done
}
Name(){
	ListeLs=`echo "$var1" | $com $1`
	echo $ListeLs
	for var in $ListeLs
	do
		if [ -d $var ]
			then
			dossi="$1/${var/".\/"}"
			cd ${var/".\/"}
			ListeN+=`echo "$V" |  Name $dossi`
			echo $ListeN" "
			cd ..

		fi

	done
}
doss="C:\Users\Public\test_os\shell"

M="MD5 $doss"
N="Name $doss"
ListeMD5=`echo "$V" |  $M`
ListeName=`echo "$V" |  $N`
echo $ListeMD5
#echo $ListeName