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

N = length(Measurement);

% Alapértelmezett visszatérési érték
DM = zeros(N,1);
DS = zeros(N,1);
PX = zeros(N,1);
PY = zeros(N,1);

% TODO: 1.1
% Elsõ körben a Measurement tömbbõl csak az elsõ elemmel dolgozzunk!
% Határozzuk meg a legnagyobb RMS értékû csatorna indexét külön slave és
% master esetben

% the nice way would be something like:
% [~,master_max_index] = max(rms(vertcat(Measurement.Result( ...
%   strcmp({Measurement.Result.MasterSlave},'master')).Sample)'))

for measure_index = 1 : N
    results = Measurement(measure_index).Result;
    master_results(measure_index,:) = results( ...
        strcmp({results.MasterSlave},'master'));
    slave_results(measure_index,:) = results( ...
        strcmp({results.MasterSlave},'slave'));
    master_channels(measure_index,:,:) = vertcat( ...
        master_results(measure_index,:).Sample);
    slave_channels(measure_index,:,:) = vertcat( ...
        slave_results(measure_index,:).Sample);
    master_rms_values = rms(squeeze(master_channels(measure_index,:,:))');
    slave_rms_values = rms(squeeze(slave_channels(measure_index,:,:))');
    [~,master_max_channel_index(measure_index) ] = max(master_rms_values);
    [~,slave_max_channel_index(measure_index) ] = max(slave_rms_values);
end


% TODO: 1.2
% Minták közül a lemagasabb érték indexének meghatározása (master, slave)
for measure_index = 1 : N
    [~,master_max_value_index(measure_index)] = max(master_channels( ...
        measure_index,master_max_channel_index(measure_index),:));
    [~,slave_max_value_index(measure_index)] = max(slave_channels( ...
        measure_index,slave_max_channel_index(measure_index),:));
end

% TODO: 1.3
% Terjedési idõ számolása (master, slave)
% Figyeljünk a korrekciós tényezõre!
% t = t1 + Ts * kmax − tO1 − tO2 | tO1 = 1700e-6 s, tO2 = 400e-6 s
tO1 = 1700e-6;
tO2 =  400e-6;
correct_time = 1;
if correct_time
    time_corr_master = -0.0001391454042697623;
    time_corr_slave = -0.0001429917565434142;
else
    time_corr_master = 0;
    time_corr_slave = 0;
end
for measure_index = 1 : N
    master_propagation_time(measure_index) = ...
        master_results(measure_index,master_max_channel_index(measure_index)).TimeBeforeBurst ...
      + master_results(measure_index,master_max_channel_index(measure_index)).SamplingTime * master_max_value_index(measure_index) ...
      - tO1 - tO2 - time_corr_master;
    slave_propagation_time(measure_index) = ...
        slave_results(measure_index,slave_max_channel_index(measure_index)).TimeBeforeBurst ...
      + slave_results(measure_index,slave_max_channel_index(measure_index)).SamplingTime * slave_max_value_index(measure_index) ...
      - tO1 - tO2 - time_corr_slave;
end

% TODO: 1.4
% Hangsebesség meghatározása aktuális hõmérséklet alapján
% Figyeljünk a mértékegységekre!
% c = 331.3m/s * sqrt( T / 273.15K )
for measure_index = 1 : N
    sound_speed(measure_index) =  331.3 * ...
        sqrt(1 + Measurement(measure_index).Temperature / 273.15);
end


% TODO: 1.5
% Távolságok és poziciók meghatározása (master, slave)
% Használjuk a DM, DS, PX és PY változókat!
% A vevõ egységek távolsága 1.4m volt.
D = 1.4;
DM = master_propagation_time .* sound_speed;
DS = slave_propagation_time .* sound_speed;
PX = (D*D - DM.*DM + DS.*DS) / (2*D);
PY = sqrt(DS.*DS - PX.*PX);

% TODO: 2.1
% Módosítsuk a programot, hogy mind a tíz mérés eredményét számolja ki és
% adja vissza
    


end % of function CalculatePosition