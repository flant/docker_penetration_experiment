# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|
  config.vm.box = 'ubuntu/trusty64'
  config.vm.box_check_update = false
  config.vm.provider 'virtualbox' do |v|
    v.memory = 1024
  end

  config.vm.provision "shell", inline: <<-END
    cd /vagrant
    gcc unshare.c -o unshare
    gcc setns.c -o setns
  END
end
