with Ada.Text_IO; use Ada.Text_IO;
procedure main is 
a : Integer := 0;
begin
while a<=100 loop
Put_Line("" & Integer'Image(a) & "");
if (a mod 3) = 0 then
Put_Line("fizz");
end if;
if (a mod 5) = 0 then
Put_Line("buzz");
end if;
New_Line;

a := a+1;
end loop;


end main;
