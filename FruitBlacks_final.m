function fruit


fid = fopen('C:\Users\Gena\Desktop\MATALB\Report.txt', 'wt');
 while(1);
prompt = 'Enter the name of file:  '; % name of file


fname = input(prompt,'s'); % name of input image
fruit = imread(fname);		% name of image in the program



width = 810;		%size of image ---> (resize)
images = {fruit};	

 dim = size(images{1}); %size images
 images{1} = imresize(images{1},[width*dim(1)/dim(2) width],'bicubic');

 fruit = images{1};		%string of name

srgb2lab = makecform('srgb2lab');	%conver image
lab2srgb = makecform('lab2srgb');	%---//---

shadow_lab = applycform(fruit, srgb2lab); % convert to L*a*b*   %---//---

% the values of luminosity can span a range from 0 to 100; scale them
% to [0 1] range (appropriate for MATLAB(R) intensity images of class double) 
% before applying the three contrast enhancement techniques


max_luminosity = 1; 		%luminosity ---> ???????
L = shadow_lab(:,:,1)/max_luminosity;			

% replace the luminosity layer with the processed data and then convert
% the image back to the RGB colorspace

shadow_imadjust = shadow_lab; 
shadow_imadjust(:,:,1) = imadjust(L)*max_luminosity;
shadow_imadjust = applycform(shadow_imadjust, lab2srgb);

shadow_histeq = shadow_lab;
shadow_histeq(:,:,1) = histeq(L)*max_luminosity;
shadow_histeq = applycform(shadow_histeq, lab2srgb);

shadow_adapthisteq = shadow_lab;
shadow_adapthisteq(:,:,1) = adapthisteq(L)*max_luminosity;
shadow_adapthisteq = applycform(shadow_adapthisteq, lab2srgb);



% convert the image in gray-scale
% red green blue ---> convert to gray-scale image
I = rgb2gray(fruit);
fruit_imadjust = imadjust(I,[0.35 0.9],[0 1]);
m = 256; % number of sub gray collors

figure
% bar plot

[counts, binLocation] = imhist(I,m); %count bin location on axis (X side) and values of intensities (Y side)  
bar(binLocation,counts, 'FaceColor', [0 .5 .5], 'EdgeColor', [0 .5 .5]); % bar ---> ||||| (column histogram)
axis([0 256 0 20000]); 
colormap gray;
colorbar('SouthOutside'); 
% res1=0;
% res2=0;
% res3=0;
sum1 = 0;
for k=1:130
   sum1=sum1+counts(k); 
end
res1 = sum1/130;
sum2 = 0;
for k=131:190
   sum2=sum2+counts(k); 
end
res2=sum2/59;
sum3 = 2;
for k=191:255
   sum3=sum3+counts(k); 
end
res3=sum3/64;

% for k = 1:m % like ---> for(i=0;i<...;i++)
    fprintf (fid,'%10.2f\n%10.2f\n%10.2f\n', res1,res2,res3); % print results: counts ---> Y binLocation ---> X
    
% end
%

% binLocation(k)--> after counts(k)%10.2f 
str = {'Original', 'Imadjust', 'Adapthisteq', 'Original-gray', 'Imadjust-gray'};
%Figures
figure, imshow(fruit);
title(str{1});

figure;
% input images into sheet square 
subplot(2,2,1),imshow(shadow_imadjust), title (str{2});
subplot(2,2,2),imshow(shadow_adapthisteq), title (str{3});
subplot(2,2,3), imshow(I), title (str{4});
subplot(2,2,4),imshow(fruit_imadjust), title (str{5});

% Report
prompt = 'If the fruit high quality or not? (yes/no):   ';% change
originality = input(prompt,'s');

% fprintf (fid, ' %6s %6s \n', fname, originality);



answer=input('Do you want to continue, Y/N [Y]/[N]:','s');
if (answer=='N' || answer=='n')
break
end    



 end
 fclose(fid);
end

