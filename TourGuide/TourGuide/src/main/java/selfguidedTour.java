/*
    This is one of the base tours you can take
*/


public class selfguidedTour implements Tour {
   @Override
   public String getDescription()
   {
       return "A self-guided tour of the mansion ";
   }
    
   @Override
    public double getCost()
    {
        return 55;
    }
    
   @Override
    public int getMinTimeInMinutes()
    {
        return 90;
    }
}
