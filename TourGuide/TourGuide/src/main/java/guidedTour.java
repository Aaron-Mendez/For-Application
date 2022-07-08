/*
    This is one of the base tours you can take
*/

public class guidedTour implements Tour {

    @Override
    public String getDescription()
   {
       return "A guided tour of the mansion ";
   }
    
    @Override
    public double getCost()
    {
        return 80;
    }
    
    @Override
    public int getMinTimeInMinutes()
    {
        return 90;
    }
}
