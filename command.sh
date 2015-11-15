./Opengl3.app/Contents/MacOS/Opengl3 | ffmpeg -vcodec rawvideo -f rawvideo -pix_fmt rgb24 -s 640x480 -i - -f mpeg1video -b 800k -r 30 http://127.0.0.1:8082/pass/640/480
