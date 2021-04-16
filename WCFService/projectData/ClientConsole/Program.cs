using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.ServiceModel;
using FilterServiceLibrary;
//using System.Drawing;

namespace ClientConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            //Bitmap
            var factory = new ChannelFactory<IContract>(new NetTcpBinding(SecurityMode.None), new EndpointAddress("net.tcp://localhost:12345/srv"));
            IContract client = factory.CreateChannel();
            //IContract client2 = factory.CreateChannel();
            Console.WriteLine(client.GetFilters()[0]);
            ImageForSend image = new ImageForSend(2, 2);
            image.pixels[0] = 20;
            Task<byte[]> filterWaitTask = new Task<byte[]>(() => ParallelMethod(client, image, "dfdf"));
            //Task<ImageForSend> filterWaitTask2 = new Task<ImageForSend>(() => ParallelMethod(client2, image, "222"));
            filterWaitTask.Start();
            //filterWaitTask2.Start();
            //image = client.ApplyFilter("dd", image);
            for (int i = 0; i < 10; ++i)
            {
                int progres = client.GetStatus();
                //int progres2 = client2.GetStatus();
                Console.WriteLine($"{i} itter, progress is {progres}");
                Thread.Sleep(800);
            }
            byte[] b = filterWaitTask.Result;
            //image = filterWaitTask2.Result;
            Console.WriteLine($"acepted image is {image.pixels[0]}");
            factory.Close();
            Console.ReadKey();
        }
        static byte[] ParallelMethod(IContract client, ImageForSend image, string filter)
        {
            byte[] b = new byte[2];
            return client.ApplyFilter(filter, b);
        }
    }
}
