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

         mov al,1        ;��ȡ�������ֽ�
         mov dx,6
         mov cx,0
     

;         mov al,2
;         mov dx,0ffffh  ;������һ���ֽ�
;         mov cx,0ffffh


;          mov al,2
;          mov dx,0h     ;�õ��ļ���С
;          mov cx,0h

          int 21H

          mov cx, 1
          mov dx,offset fBuffer
          mov ah,3fh
          int 21h             ;���ļ�

          pop bx              ;�����ļ����
    
          mov ah,3eh          ;�ر��ļ�
          int 21h
          
          .exit 0;           ;�˳�����

fName db 'd:\asm.txt',0h
fBuffer db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
end;