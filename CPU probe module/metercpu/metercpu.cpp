/* metercpu.cpp */

#include "metercpu.h"
#include<fstream>
#include<string>
#include<unistd.h>

using namespace std;
void MeterCpu::CalcForAllCpu()
{
  string crap;
  int tot_jiffies, work_jiffies, k;
  ifstream cpuStat, c2;
  cpuStat.open("/proc/stat");
  for(int cpu=0;cpu<numCpus+1;cpu++)
  {
    cpuStat >> crap;
    work_jiffies = 0;
    tot_jiffies = 0;
    for(int i=0;i<10;i++)
    {
      cpuStat >> k;
      if(i<3)
        work_jiffies+=k;
      tot_jiffies+=k;
    }
    start[cpu][0] = work_jiffies;
    start[cpu][1] = tot_jiffies;

  }
  cpuStat.close();
  usleep(1000000);
  cpuStat.open("/proc/stat");
  for(int cpu=0;cpu<numCpus+1;cpu++)
  {
    cpuStat >> crap;
    work_jiffies = 0;
    tot_jiffies = 0;
    for(int i=0;i<10;i++)
    {
      cpuStat >> k;
      if(i<3)
        work_jiffies+=k;
      tot_jiffies+=k;
    }
    end[cpu][0] = work_jiffies;
    end[cpu][1] = tot_jiffies;
  }
  for(int i=0;i<numCpus+1;i++)
    perc[i] = double((end[i][0] - start[i][0]))/double((end[i][1] - start[i][1]));
}

double MeterCpu::cpu(int i)
{
  return perc[i+1];
}


double MeterCpu::cpuAvg()
{
  return perc[0];
}

int MeterCpu::numberOfCpus()
{
	return sysconf(_SC_NPROCESSORS_ONLN);
}

long int MeterCpu::memAvail()
{
  ifstream f;
	f.open("/proc/meminfo");
	string buff;
	for(int i=0;i<7;i++)
		f >> buff;
	long int val;
	f >> val;
	f.close();
	return val;
}

long int MeterCpu::totalMemory()
{
  ifstream f;
	f.open("/proc/meminfo");
	string buff;
	long int val;
	f >> buff;
	f >> val;
	f.close();
	return val;
}

long int MeterCpu::memUsed()
{
  	return totalMemory() - memAvail();
}

long int MeterCpu::swapUsed(void)
{
	ifstream swap;
	swap.open("/proc/meminfo");
	string temp;
	long int tot, avail;
	for(;temp!="SwapTotal:";swap >> temp);
	swap >> tot;
	swap >> temp;
	swap >> temp;
	swap >> avail;
	swap.close();
	return tot - avail;
}

long int MeterCpu::swapTot(void)
{
	ifstream swap;
	swap.open("/proc/meminfo");
	string temp;
	long int k;
	for(;temp!="SwapTotal:";swap >> temp);
	swap >> k;
	swap.close();
	return k;
}

void MeterCpu::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("CalcForAllCpu"), &MeterCpu::CalcForAllCpu);
  ClassDB::bind_method(D_METHOD("cpu"), &MeterCpu::cpu);
  ClassDB::bind_method(D_METHOD("cpuAvg"), &MeterCpu::cpuAvg);
  ClassDB::bind_method(D_METHOD("numberOfCpus"), &MeterCpu::numberOfCpus);
  ClassDB::bind_method(D_METHOD("memAvail"), &MeterCpu::memAvail);
  ClassDB::bind_method(D_METHOD("totalMemory"), &MeterCpu::totalMemory);
  ClassDB::bind_method(D_METHOD("memUsed"), &MeterCpu::memUsed);
  ClassDB::bind_method(D_METHOD("swapTot"), &MeterCpu::swapTot);
  ClassDB::bind_method(D_METHOD("swapUsed"), &MeterCpu::swapUsed);
}

MeterCpu::MeterCpu()
{
  numCpus = numberOfCpus();
}
