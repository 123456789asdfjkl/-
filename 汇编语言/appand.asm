.model tiny;
.code;
.startup;

          mov ah,3dh          ;���ļ�
          mov al,03
          mov dx,offset fName
          int 21h
          push ax        ;�����ļ����
        
         mov bx,ax

         mov ah,42h      ;�ƶ�ָ��

          mov al,2
          mov dx,0  ;        �ļ�ĩβ
          mov cx,0
          int 21H

          mov cx, 13
          mov dx,offset fBuffer
          mov ah,40h
          int 21h             ;д�ļ�

          pop bx              ;�����ļ����
    
          mov ah,3eh          ;�ر��ļ�
          int 21h
          
          .exit 0;           ;�˳�����

fName db 'd:\asm.txt',0h
fBuffer db 'Added message!';
end;