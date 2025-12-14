#!/bin/bash
fechaAnt=$(date -d 'yesterday' '+%d-%m-%Y')
ayer="/var/tmp/Backups/$fechaAnt"
if [ -d $ayer ];
then
mkdir -p /var/tmp/Backups/$(date '+%d-%m-%Y')
rsync -aq --link-dest=$ayer /home/$USER/Seguridad /var/tmp/Backups/$(date '+%d-%m-%Y')
else
mkdir -p /var/tmp/Backups/$(date '+%d-%m-%Y')
rsync -aq /home/$USER/Seguridad/ /var/tmp/Backups/$(date '+%d-%m-%Y')
fi
