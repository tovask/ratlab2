function [DM, DS, PX, PY] = CalculatePosition(Measurement)
% Measurement - 1:10 vektor
%   Number - Ultrahang vevõk száma
%   Temperature - Környezeti hõmérséklet celsius fokban
%   Result - 1:8 vektor
%      MasterSlave - Ultrahang vevõ típusa
%      ChannelNumber - Csatorna száma vevõn belül
%      TimeBeforeBurst - ADC mérés idõpontja mérés kezdete óta
%      SamplingTime - Mintavételi idõ másodpercben
%      NumberOfSamples - Minták száma
%      Sample - 1:NumberOfSamples vektor
% DM - 1:10 vektor, master távolságok
% DS - 1:10 vektor, slave távolságok
% PX - 1:10 vektor, x koordináták
% PY - 1:10 vektor, y koordináták

% Alapértelmezett visszatérési érték
DM = zeros(N,1);
DS = zeros(N,1);
PX = zeros(N,1);
PY = zeros(N,1);

% TODO: 1.1
% Elsõ körben a Measurement tömbbõl csak az elsõ elemmel dolgozzunk!
% Határozzuk meg a legnagyobb RMS értékû csatorna indexét külön slave és
% master esetben



% TODO: 1.2
% Minták közül a lemagasabb érték indexének meghatározása (master, slave)



% TODO: 1.3
% Terjedési idõ számolása (master, slave)
% Figyeljünk a korrekciós tényezõre!



% TODO: 1.4
% Hangsebesség meghatározása aktuális hõmérséklet alapján
% Figyeljünk a mértékegységekre!



% TODO: 1.5
% Távolságok és poziciók meghatározása (master, slave)
% Használjuk a DM, DS, PX és PY változókat!
% A vevõ egységek távolsága 1.4m volt.



% TODO: 2.1
% Módosítsuk a programot, hogy mind a tíz mérés eredményét számolja ki és
% adja vissza
    


end % of function CalculatePosition