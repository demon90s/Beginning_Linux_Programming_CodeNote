function main
{
	#nohup python36 -m mkdocs serve -a 127.0.0.1:9999 &
	python36 -m mkdocs serve -a 127.0.0.1:9999
}

main $@
