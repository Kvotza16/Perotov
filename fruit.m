function fruit
fid = fopen('C:\Users\Gena\Desktop\MATALB\Report.txt', 'wt');


while(1);


prompt = 'Enter the name of file:  '; % name of file


fname = input(prompt,'s');
fruit = imread(fname);



width = 810;
images = {fruit};

 dim = size(images{1});
 images{1} = imresize(images{1},[width*dim(1)/dim(2) width],'bicubic');

 fruit = images{1};

srgb2lab = makecform('srgb2lab');
lab2srgb = makecform('lab2srgb');

shadow_lab = applycform(fruit, srgb2lab); % convert to L*a*b*

% the values of luminosity can span a range from 0 to 100; scale them
% to [0 1] range (appropriate for MATLAB(R) intensity images of class double) 
% before applying the three contrast enhancement techniques
max_luminosity = 1;
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
I = rgb2gray(fruit);
fruit_imadjust = imadjust(I,[0.35 0.9],[0 1]);
%grafh
figure
imhist(fruit_imadjust);

str = {'Original', 'Imadjust', 'Adapthisteq', 'Original-gray', 'Imadjust-gray'};


%Figures
figure, imshow(fruit);
title(str{1});

figure;

subplot(2,2,1),imshow(shadow_imadjust), title (str{2});
subplot(2,2,2),imshow(shadow_adapthisteq), title (str{3});
subplot(2,2,3), imshow(I), title (str{4});
subplot(2,2,4),imshow(fruit_imadjust), title (str{5});

% Report
prompt = 'If the fruit high quality or not? (yes/no):   ';% change
originality = input(prompt,'s');
fprintf(fid, '%s     %s''\n', fname,originality);
%prompt = 'Enter data from the graph:   ';
%range = input(prompt,'s');
%fprintf(fid, '%s     %s''\n', fname,range);


answer = input('Do you want to continue? Y/N [Y]/[N]:', 's');
if answer == 'N'
 break;
end

end
end

