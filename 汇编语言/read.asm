.model tiny;
.code;
.startup;

          mov ah,3dh          ;���ļ�
          mov al,03
          mov dx,offset fName
          int 21h
          push ax             ;�����ļ����

          mov bx,ax
          mov cx, 12
          mov dx,offset fBuffer
          mov ah,3fh
          int 21h             ;���ļ�

          pop bx              ;�����ļ����

          mov ah,3eh          ;�ر��ļ�
          int 21h
          
          .exit 0;           ;�˳�����

fName db 'd:\data.txt',0h
fBuffer db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
end;