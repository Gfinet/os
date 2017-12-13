MD5(){
	com="ls -R --sort=extension"
	origine=$1
	dossiers=""
	cd $1
	ListeLs+=`echo "$var1" | find `
	#echo $ListeLs
	for var in $ListeLs
	do
		ech=false
		var=$origine${var/"."}

		for ver in $ListeLs
		do
			echo $var" -- "
			ver=$origine${ver/"."}
			if [ -e $var ] && [ "$var" != "$ver" ] && [ ! -d $var ] && [ ! -d $ver ]
				then

				a=md5sum $var
				b=md5sum $ver 
				if [ "$a" == "$b" ]
					then

					if [ "$ech" != true ]
						then
						ech=true
						echo $var","
					fi
					echo $ver","
				fi
				
			fi
		done
		#retour à la ligne
	done
}
x(){
 echo 'lol'	
}

doss="C:\Users\Public\test_os\shell"

M="MD5 $doss"
N="Name $doss"
ListeMD5=`echo "$V" |  $M`
#ListeName=`echo "$V" |  $N`
echo $ListeMD5
#echo $ListeName