.model tiny;
.code;
.startup;

          mov ah,3dh          ;���ļ�
          mov al,02           ;��д
          mov dx,offset fName
          int 21h
          push ax        ;�����ļ����
        
          mov bx,ax
          mov cx,82
          mov dx,offset fBuffer2
          mov ah,3fh
          int 21h   ;���ļ�
          push ax ;���������ֽ���

        ;  mov ah,41
        ;  mov dx
       ;   int 21;ɾ���ļ�

         mov ah,42h      ;�ƶ�ָ��
         mov al,0
         mov dx,0  ;        �ļ�ĩβ
         mov cx,0
         int 21H

        
          pop ax ;ȡ�ó���
          push ax;
          ;add ax,30 ;ascii��  
          ;lea si,fBuffer
          ;mov cl,al
          ;shr cl,4
          ;add cl,30
         ; mov [si+9],cl
          ;mov ch,al
         ; shl ch,4
         ; shr ch,4
         ; add ch,30
          ;mov [si+10],ch
          ;mov word ptr [si+9],'12'
          mov dx,offset fBuffer 
          mov cx, 11
          mov ah,40h
          int 21h             ;д�ļ�
          
         


          pop ax
          add ax,2
          mov cx, ax
          lea si,offset fBuffer2
          sub si,2
          mov byte ptr [si],0dh
          mov byte ptr [si+1],0ah
          mov dx,si
          mov ah,40h
          int 21h             ;д�ļ�

          

          pop bx              ;�����ļ����
    
          mov ah,3eh          ;�ر��ļ�
          int 21h
          
          .exit 0;           ;�˳�����

fName db 'd:\myinfo.txt',0h
fBuffer db 'filesize:87';
fBuffer2 db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;

end;